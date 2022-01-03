def ComputeVelocity(moveRight, moveUp, moveLeft, moveDown):
	MOV_SPEED_MUL = 100.0
	x = 0.0
	y = 0.0

	if (moveRight):
		x = MOV_SPEED_MUL
	elif(moveUp):
		y = -MOV_SPEED_MUL
	elif(moveLeft):
		x = -MOV_SPEED_MUL
	elif(moveDown):
		y = MOV_SPEED_MUL
	return x,y