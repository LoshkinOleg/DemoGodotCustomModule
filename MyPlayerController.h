#ifndef MY_PLAYER_CONTROLLER_H
#define MY_PLAYER_CONTROLLER_H

#include "core/reference.h"
#include "core/math/vector2.h"

class MyPlayerController : public Reference
{
	GDCLASS(MyPlayerController, Reference);
	
protected:
	static void _bind_methods();
	
public:
	Vector2 ComputeVelocity(bool moveRight, bool moveUp, bool moveLeft, bool moveDown);
	
	MyPlayerController();
};

#endif //!MY_PLAYER_CONTROLLER_H