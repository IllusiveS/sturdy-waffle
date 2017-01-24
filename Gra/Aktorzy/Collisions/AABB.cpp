//
// Created by wysockipatryk on 1/17/17.
//

#include "AABB.h"

AABB::AABB(Vector2 center, Vector2 halfSize) : center(center), halfSize(halfSize) {

}

bool AABB::Overlaps(AABB other) {
	if(abs(center.y - other.center.y) > halfSize.y + other.halfSize.y) return false;
	return true;
}
