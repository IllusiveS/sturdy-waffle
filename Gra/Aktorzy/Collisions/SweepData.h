//
// Created by wysockipatryk on 1/18/17.
//

#ifndef SDLPODSTAWA_EXE_SWEEPDATA_H
#define SDLPODSTAWA_EXE_SWEEPDATA_H

class IPhysicsable;

struct SweepData {
	SweepData(IPhysicsable * coll, int p, bool isBegin);
	~SweepData();

	IPhysicsable * collider;
	int pos;
	bool isBegin;

	bool operator<(const SweepData &rhs) const;

	bool operator>(const SweepData &rhs) const;

	bool operator<=(const SweepData &rhs) const;

	bool operator>=(const SweepData &rhs) const;
};

#endif //SDLPODSTAWA_EXE_SWEEPDATA_H
