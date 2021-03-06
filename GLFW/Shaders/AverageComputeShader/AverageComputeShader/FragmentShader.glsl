/*
Title: AverageComputeShader
File Name: FragmentShader.glsl
Copyright � 2015
Original authors: Brockton Roth
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
Improves on the BasicComputeShader, taking advantage of the parallelization 
and drawing a spinning circle of points (dots, essentially). Each color is 
based off of the vertex ID (retrieved via gl_GlobalInvocationID) and each 
position is based off of a sin, cos, and radius to create the circle (the 
angle is also calculated using the gl_GlobalInvocationID). This allows for 
fast computation. The radius is set via a uniform variable, and the code 
has it growing to a certain point, then shrinking again, and repeating.

WARNING: Requires OpenGL version 4.3 or later for the compute shader to compile.
*/

#version 400 core // Identifies the version of the shader, this line must be on a separate line from the rest of the shader code

layout(location = 0) out vec4 out_color; // Establishes the variable we will pass out of this shader.

in vec4 color;	// Take in a vec4 for color
 
void main(void)
{
	out_color = color;	// Set our out_color equal to our in color, basically making this a pass-through shader.
}