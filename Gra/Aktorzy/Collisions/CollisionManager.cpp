//
// Created by wysockipatryk on 1/18/17.
//

#include <set>
#include <map>
#include <algorithm>
#include <future>
#include <iostream>
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
//	printf("Begin sort\n");
	for(auto itr = objects.begin(); itr != objects.end(); itr++) {
		IPhysicsable * object = *itr;
		object->CalculatePhysics(delta);
		sweepData.insert(object->getBeginSweepData());
		sweepData.insert(object->getEndSweepData());
	}
//	printf("End sort\n");

	std::map<IPhysicsable *, std::list<IPhysicsable *>> intersections;

	std::list<std::future<int>> futures = std::list<std::future<int>>();

//	printf("Begin sweep\n");
	for(auto itr = sweepData.begin(); itr != sweepData.end(); itr++) {
		SweepData currentData = *itr;
//		printf("current data %i\n", currentData.pos);
		if(currentData.isBegin) {
			for(auto dataItr = intersections.begin(); dataItr != intersections.end(); dataItr++) {
				dataItr->second.push_back(currentData.collider);
			}
			intersections.insert(std::pair<IPhysicsable *, std::list<IPhysicsable *>>(currentData.collider, std::list<IPhysicsable *>()));
		} else {
			auto finalDataIterator = std::find_if(intersections.begin(), intersections.end(), [currentData]
					(const std::pair<IPhysicsable *, std::list<IPhysicsable *>> data) {
				return data.first == currentData.collider;
			});
			std::pair<IPhysicsable *, std::list<IPhysicsable *>> finalSet = *finalDataIterator;
			intersections.erase(finalDataIterator);
			int intersectionsInFinalSetFound = finalSet.second.size();
			if(!intersectionsInFinalSetFound == 0 ){
				IPhysicsable * dataToCheck = finalSet.first;
				std::list<IPhysicsable *> listToSweep = finalSet.second;

				std::for_each(listToSweep.begin(), listToSweep.end(),[=](IPhysicsable * currentChecked){
					if(currentChecked->checkCollision(dataToCheck)) {
						currentChecked->collide(dataToCheck);
						dataToCheck->collide(currentChecked);
					}
				});
			}
		}
	}
//	printf("End sweep\n");
}

void CollisionManager::calculatePhysics(std::pair<SweepData, std::list<SweepData>> pair) {

}