//
// Created by wysockipatryk on 1/7/17.
//

#ifndef SDLPODSTAWA_EXE_IPHISICSABLE_H
#define SDLPODSTAWA_EXE_IPHISICSABLE_H


class IPhisicsable {
public:
	IPhisicsable();
	~IPhisicsable();

	virtual void CalculatePhisics(float delta) = 0;
};

#endif //SDLPODSTAWA_EXE_IPHISICSABLE_H
