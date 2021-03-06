/*
Title: Bezier curve tessellation
File Name: GLIncludes.h
Copyright � 2015
Original authors: Srinivasan T
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Description:
This program demonstrates the implementation of bezier curve with the tessellation 
being computed in the shader. In this program, we send only the control points to 
the shader and adjust the tessellation level accordingly.

The tessellation control shader begins by defining the number of vertices in the 
output patch: layout (vertices = 4) out;

Note that this is not the same number of vertices that will be produced by the process.
In this case the number of control points are 4, so we pass 4 in one patch.

The vertex sahder simply passes the input data as read from the buffer to the next shader
(tessellation control shader). The TCS sets the tessellation levels by assigning a value to 
gl_TessLevlOuter array. The first element defines the number of isolines that will be generated.
In this example that value will be 1. The second value defines the number of line segments per 
isoline. 

In tessellation evaluation shader, we start by defining the input primitive type using a layout
declaration: layout (isolines) in;
In TCS, we access the uv coordinates using glTessCoord. Then we access the position of the 
four control points (all the points in our patch). Using these values we compute the bernstein 
polynomials at given uv cordinates and calculate the position. 

References:
OpenGL 4 Shading language cookbook (second edition)

*/

#ifndef _GL_INCLUDES_H
#define _GL_INCLUDES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "glew\glew.h"
#include "glfw\glfw3.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "glm\gtc\quaternion.hpp"
#include "glm\gtx\quaternion.hpp"

// We create a VertexFormat struct, which defines how the data passed into the shader code wil be formatted
struct VertexFormat
{
	glm::vec4 color;	// A vector4 for color has 4 floats: red, green, blue, and alpha
	glm::vec3 position;	// A vector3 for position has 3 float: x, y, and z coordinates

	// Default constructor
	VertexFormat()
	{
		color = glm::vec4(0.0f);
		position = glm::vec3(0.0f);
	}

	// Constructor
	VertexFormat(const glm::vec3 &pos, const glm::vec4 &iColor)
	{
		position = pos;
		color = iColor;
	}
};

#endif _GL_INCLUDES_H