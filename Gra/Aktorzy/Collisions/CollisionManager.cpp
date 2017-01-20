//
// Created by wysockipatryk on 1/18/17.
//

#include <set>
#include <map>
#include <algorithm>
#include <future>
#include "CollisionManager.h"
#include "SweepData.h"

void CollisionManager::subscribePhysicable(IPhysicsable * object) {
	objects.push_back(object);
}

void CollisionManager::unSubscribePhysicable(IPhysicsable * object) {
	objects.remove(object);
}

void CollisionManager::processPhysics(float delta) {
	std::set<SweepData> sweepData;
	for(auto itr = objects.begin(); itr != objects.end(); itr++) {
		IPhysicsable * object = *itr;
		object->CalculatePhysics(delta);
		sweepData.insert(object->getBeginSweepData());
		sweepData.insert(object->getEndSweepData());
	}

	//TODO zamienić SweepData na IPhysicsable w tym miejscu
	std::map<SweepData, std::list<SweepData>> intersections;

	std::list<std::future<int>> futures = std::list<std::future<int>>();

	for(auto itr = sweepData.begin(); itr != sweepData.end(); itr++) {
		SweepData currentData = *itr;
		if(currentData.isBegin) {
			for(auto dataItr = intersections.begin(); dataItr != intersections.end(); dataItr++) {
				std::pair<SweepData, std::list<SweepData>> beginData = *dataItr;
				beginData.second.push_back(currentData);
				intersections.insert(beginData);
			}
			intersections.insert(std::pair<SweepData, std::list<SweepData>>(currentData, std::list<SweepData>()));
		} else {
			auto finalDataIterator = std::find_if(intersections.begin(), intersections.end(), [currentData]
					(const std::pair<SweepData, std::list<SweepData>> data) {
				return data.first.collider == currentData.collider;
			});
			std::pair<SweepData, std::list<SweepData>> finalSet = *finalDataIterator;
			intersections.erase(finalDataIterator);
			int intersectionsInFinalSetFound = finalSet.second.size();
			if(!intersectionsInFinalSetFound == 0 ){
				futures.push_back(std::async(std::launch::async, [finalSet](){
					SweepData dataToCheck = finalSet.first;
					std::list<SweepData> listToSweep = finalSet.second;

					std::for_each(listToSweep.begin(), listToSweep.end(),[=](SweepData currentChecked){
						if(currentChecked.collider->checkCollision(dataToCheck.collider)) {
							currentChecked.collider->collide(dataToCheck.collider);
							dataToCheck.collider->collide(currentChecked.collider);
						}
					});
					return 0;
				}));
			}
		}
	}
	std::for_each(futures.begin(), futures.end(), [](std::future<int> &future) {
		future.get();
	});

}

void CollisionManager::calculatePhysics(std::pair<SweepData, std::list<SweepData>> pair) {

}