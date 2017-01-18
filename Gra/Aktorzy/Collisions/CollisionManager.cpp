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
		sweepData.insert(object->getBeginSweepData());
		sweepData.insert(object->getEndSweepData());
	}

	//TODO zamienić SweepData na IPhysicsable w tym miejscu
	std::map<SweepData, std::list<SweepData>> intersections;

	std::list<std::future<void>> futures = std::list<std::future<void>>();

	for(auto itr = sweepData.begin(); itr != sweepData.end(); itr++) {
		SweepData currentData = *itr;
		if(currentData.isBegin) {
			for(auto dataItr = intersections.begin(); dataItr != intersections.end(); dataItr++) {
				std::pair<SweepData, std::list<SweepData>> beginData = *dataItr;
				beginData.second.push_back(currentData);
			}
			intersections.insert(std::pair(currentData, std::list<SweepData>()));
		} else {
			auto finalDataIterator = std::find_if(intersections.begin(), intersections.end(), [currentData](const SweepData data) {
				return data.collider == currentData.collider;
			});
			std::pair<SweepData, std::list<SweepData>> finalSet = *finalDataIterator;
			intersections.erase(finalDataIterator);
			//TODO sprawdzenie kolzji na finalSet lambdą futurem i wątkiem
			futures.push_back(std::async(std::launch::async, [finalSet](){
				//TODO sprawdzenie każdego z każdym i wywołanie kolzji
				SweepData dataToCheck = finalSet.first;
				std::list<SweepData> listToSweep = finalSet.second;

				std::for_each(listToSweep.begin(), listToSweep.end(),[](SweepData currentChecked){
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

void CollisionManager::calculatePhysics(std::pair<SweepData, std::list<SweepData>> pair) {

}