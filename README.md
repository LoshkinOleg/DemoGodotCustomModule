# DemoGodotCustomModule

Simple Custom C++ module for Godot to demonstrate how to create code in C++ that is exposed in Godot's scripts. The C++ code can then embed python code.
In this case, it's a simple class that implements a method that calls a python function that computes a new velocity by taking in boolean inputs for WASD.

To use it:
- Clone the latest stable release of Godot (the latest code on main has gotten rid of the core/reference.h file apparently).
- Clone this repo into godot/modules.
- Rename the folder to "MyPlayerController". This is important because Godot uses the folder's name for binding to your code.
- Move the python*.lib library files located in extern/python310/libs/ into godot/. Couldn't find a way to make Godot's scons search for the correct .lib files in the correct locations. Once these files have been moved, the extern/python310/libs/ can be deleted as it isn't used otherwise.
- Launch powershell from godot/ and compile it with "scons platform=windows".
- Launch Godot and use the class from GDScript like so:
	var myController = MyPlayerController.new()
	var newVelocity = myController.ComputeVelocity(<inputs here>)
