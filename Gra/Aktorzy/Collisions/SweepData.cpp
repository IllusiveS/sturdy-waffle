//
// Created by wysockipatryk on 1/18/17.
//

#include "SweepData.h"

SweepData::SweepData(IPhysicsable * coll, int p, bool isBegin)
		: isBegin(isBegin), collider(coll), pos(p) {

}

SweepData::~SweepData() {

}

bool SweepData::operator==(const SweepData &data) const {
	return pos == data.pos;
}

bool SweepData::operator<(const SweepData &rhs) const {
	if(*this == rhs) {
		if(this->isBegin && rhs.isBegin) {
			return true;
		} else if (!this->isBegin && rhs.isBegin) {
			return false;
		} else if (this->isBegin && !rhs.isBegin) {
			return true;
		} else if (!this->isBegin && !rhs.isBegin) {
			return false;
		}
	}
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
