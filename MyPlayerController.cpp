#include "MyPlayerController.h"

#include "extern/pybind11/include/pybind11/pybind11.h"

Vector2 MyPlayerController::ComputeVelocity(bool moveRight, bool moveUp, bool moveLeft, bool moveDown)
{
	const float MOV_SPEED_MUL = 100.0f;
	
	if (moveRight)
	{
		return Vector2(1.0f, 0.0f) * MOV_SPEED_MUL;
	}
	else if(moveUp)
	{
		return Vector2(0.0f, 1.0f) * -MOV_SPEED_MUL;
	}
	else if(moveLeft)
	{
		return Vector2(-1.0f, 0.0f) * MOV_SPEED_MUL;
	}
	else if(moveDown)
	{
		return Vector2(0.0f, -1.0f) * -MOV_SPEED_MUL;
	}
	else
	{
		return Vector2(0.0f, 0.0f);
	}
}

void MyPlayerController::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("ComputeVelocity", "moveRight", "moveUp", "moveLeft", "moveDown"), &MyPlayerController::ComputeVelocity);
}

MyPlayerController::MyPlayerController()
{
	
}