//
// Created by wysockipatryk on 1/18/17.
//

#include "SweepData.h"

SweepData::SweepData(IPhysicsable * coll, int p, bool isBegin)
		: isBegin(isBegin), collider(coll), pos(p) {

}

SweepData::~SweepData() {

}

bool SweepData::operator<(const SweepData &rhs) const {
	return pos < rhs.pos;
}

bool SweepData::operator>(const SweepData &rhs) const {
	return rhs < *this;
}

bool SweepData::operator<=(const SweepData &rhs) const {
	return !(rhs < *this);
}

bool SweepData::operator>=(const SweepData &rhs) const {
	return !(*this < rhs);
}
