//
// Created by wysockipatryk on 12/26/16.
//

#include <Gra/Game.h>
#include "ITickable.h"

ITickable::ITickable() {
	Game::GetGame()->SubscribeTick(this);
}
