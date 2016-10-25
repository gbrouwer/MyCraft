#include <math.h>           /* C header for any math functions               */
#include <stdio.h>          /* C header for standard I/O                     */
#include <string.h>         /* For String compare                            */
#include <stdlib.h>
#include <GLUT/glut.h>	  
#include <parameters.h>


//-------------------------------------------------------------------------------------------------------
float vectorlength(float vector[3])
{

	return sqrt(vector[0]*vector[0] + vector[1]*vector[1] + vector[2]*vector[2]);

}
//-------------------------------------------------------------------------------------------------------
void normalize(float vector[3])
{
	float length = vectorlength(vector);
	player.vectorGlobal[0] = vector[0] / length;
	player.vectorGlobal[1] = vector[1] / length;
	player.vectorGlobal[2] = vector[2] / length;

}
//-------------------------------------------------------------------------------------------------------
void calculateNormal(float v0[3], float v1[3], float v2[3])
{

	float v[3];
	float u[3];
	
	//Define V and U
	v[0] = v1[0] - v0[0];
	v[1] = v1[1] - v0[1];
	v[2] = v1[2] - v0[2];
	u[0] = v2[0] - v0[0];
	u[1] = v2[1] - v0[1];
	u[2] = v2[2] - v0[2];
	
	//Crossproduct
	player.vectorNormal[0] = (v[1] * u[2]) - (v[2] * u[1]);
	player.vectorNormal[1] = (v[2] * u[0]) - (v[0] * u[2]);
	player.vectorNormal[2] = (v[0] * u[1]) - (v[1] * u[0]);

}
//-------------------------------------------------------------------------------------------------------
