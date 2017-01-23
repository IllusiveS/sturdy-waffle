//
// Created by wysockipatryk on 12/26/16.
//

#ifndef SDLPODSTAWA_ITICKABLE_H
#define SDLPODSTAWA_ITICKABLE_H


class ITickable {
public:
	ITickable();
	virtual ~ITickable();

	virtual void Tick(float delta) = 0;
};

#endif //SDLPODSTAWA_ITICKABLE_H
