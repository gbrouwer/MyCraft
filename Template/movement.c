#include <math.h>           /* C header for any math functions               */
#include <stdio.h>          /* C header for standard I/O                     */
#include <string.h>         /* For String compare                            */
#include <stdlib.h>
#include <GLUT/glut.h>	  
#include <parameters.h>


//-------------------------------------------------------------------------------------------------------
void InitializePosition(void)
{

	//Initial Looking Direction
	if (psycho.on == 1)
		{
		player.vectorEye[0] = psycho.startPosition[0];
		player.vectorEye[1] = psycho.startPosition[1];
		player.vectorEye[2] = psycho.startPosition[2];
		}
	else
		{
		player.vectorEye[0] = -1.0;
		player.vectorEye[1] = 0.5000;
		player.vectorEye[2] = 1.0;
		}
	
	player.vectorUp[0] = 0;
	player.vectorUp[1] = 1;
	player.vectorUp[2] = 0;
	player.vectorRight[0] = 0;
	player.vectorRight[1] = 0;
	player.vectorRight[2] = 1;
	dist = 1 * cos(frustum.elevation);
	player.vectorLook[0] = sin(frustum.azimuth) * dist;
	player.vectorLook[1] = 1 * sin(frustum.elevation);
	player.vectorLook[2] = cos(frustum.azimuth) * dist;
	player.vectorLook[0] = player.vectorLook[0] + player.vectorEye[0];
	player.vectorLook[1] = player.vectorLook[1] + player.vectorEye[1];
	player.vectorLook[2] = player.vectorLook[2] + player.vectorEye[2];

}
//-------------------------------------------------------------------------------------------------------
void RotateRight()
{

	//Get Azimuth and Elevation
	x = player.vectorLook[0] - player.vectorEye[0];
	y = player.vectorLook[2] - player.vectorEye[2];
	z = player.vectorLook[1] - player.vectorEye[1];
	frustum.azimuth = atan2(x,y);
	dist = sqrt(x*x + y*y);
	frustum.elevation = atan2(z,dist);
	
	//Add to azimuth
	frustum.azimuth = frustum.azimuth - moving.rotationspeed;

	//Convert back
	dist = 1 * cos(frustum.elevation);
	player.vectorLook[0] = player.vectorEye[0] + sin(frustum.azimuth) * dist;
	player.vectorLook[1] = player.vectorEye[1] + 1 * sin(frustum.elevation);
	player.vectorLook[2] = player.vectorEye[2] + cos(frustum.azimuth) * dist;
	CollisionDetection();

}
//-------------------------------------------------------------------------------------------------------
void RotateLeft()
{

	//Get Azimuth and Elevation
	x = player.vectorLook[0] - player.vectorEye[0];
	y = player.vectorLook[2] - player.vectorEye[2];
	z = player.vectorLook[1] - player.vectorEye[1];
	frustum.azimuth = atan2(x,y);
	dist = sqrt(x*x + y*y);
	frustum.elevation = atan2(z,dist);

	//Add to azimuth
	frustum.azimuth = frustum.azimuth + moving.rotationspeed;

	//Convert back
	dist = 1 * cos(frustum.elevation);
	player.vectorLook[0] = player.vectorEye[0] + sin(frustum.azimuth) * dist;
	player.vectorLook[1] = player.vectorEye[1] + 1 * sin(frustum.elevation);
	player.vectorLook[2] = player.vectorEye[2] + cos(frustum.azimuth) * dist;
	CollisionDetection();


}
//-------------------------------------------------------------------------------------------------------
void RotateDown()
{
	
	//Get Azimuth and Elevation
	x = player.vectorLook[0] - player.vectorEye[0];
	y = player.vectorLook[2] - player.vectorEye[2];
	z = player.vectorLook[1] - player.vectorEye[1];
	frustum.azimuth = atan2(x,y);
	dist = sqrt(x*x + y*y);
	frustum.elevation = atan2(z,dist);
	
	//Add to elivation
	frustum.elevation = frustum.elevation - moving.rotationspeed;
	if (frustum.elevation < -1.5)
		{frustum.elevation = -1.5;}

	//Convert back
	dist = 1 * cos(frustum.elevation);
	player.vectorLook[0] = player.vectorEye[0] + sin(frustum.azimuth) * dist;
	player.vectorLook[1] = player.vectorEye[1] + 1 * sin(frustum.elevation);
	player.vectorLook[2] = player.vectorEye[2] + cos(frustum.azimuth) * dist;


}
//-------------------------------------------------------------------------------------------------------
void RotateUp()
{

	//Get Azimuth and Elevation
	x = player.vectorLook[0] - player.vectorEye[0];
	y = player.vectorLook[2] - player.vectorEye[2];
	z = player.vectorLook[1] - player.vectorEye[1];
	frustum.azimuth = atan2(x,y);
	dist = sqrt(x*x + y*y);
	frustum.elevation = atan2(z,dist);
	
	//Add to elivation
	frustum.elevation = frustum.elevation + moving.rotationspeed;
	if (frustum.elevation > 1.5)
		{frustum.elevation = 1.5;}

	//Convert back
	dist = 1 * cos(frustum.elevation);
	player.vectorLook[0] = player.vectorEye[0] + sin(frustum.azimuth) * dist;
	player.vectorLook[1] = player.vectorEye[1] + 1 * sin(frustum.elevation);
	player.vectorLook[2] = player.vectorEye[2] + cos(frustum.azimuth) * dist;


}
//-------------------------------------------------------------------------------------------------------
void MoveForward()
{

	//Normalize Directional Vector
	player.vectorNormal[0] = player.vectorEye[0] - player.vectorLook[0];
	player.vectorNormal[1] = player.vectorEye[1] - player.vectorLook[1];
	player.vectorNormal[2] = player.vectorEye[2] - player.vectorLook[2];
	normalize(player.vectorNormal);
	player.vectorNormal[0] = player.vectorGlobal[0];player.vectorNormal[1] = player.vectorGlobal[1];player.vectorNormal[2] = player.vectorGlobal[2];
	
	
	//Add Step Forward
	player.vectorEye[0] = player.vectorEye[0] - moving.stepsize*timing.elapsed*player.vectorNormal[0];
	player.vectorEye[1] = player.vectorEye[1] - moving.stepsize*timing.elapsed*player.vectorNormal[1]*0;
	player.vectorEye[2] = player.vectorEye[2] - moving.stepsize*timing.elapsed*player.vectorNormal[2];
	player.vectorLook[0] = player.vectorLook[0] - moving.stepsize*timing.elapsed*player.vectorNormal[0];
	player.vectorLook[1] = player.vectorLook[1] - moving.stepsize*timing.elapsed*player.vectorNormal[1]*0;
	player.vectorLook[2] = player.vectorLook[2] - moving.stepsize*timing.elapsed*player.vectorNormal[2];

	CollisionDetection();
	if (frustum.collision > 0)
		{
		player.vectorEye[1] = player.vectorEye[1] + 0.005;
		player.vectorLook[1] = player.vectorLook[1] + 0.005;
		//Undo
		//player.vectorEye[0] = player.vectorEye[0] + moving.stepsize*timing.elapsed*player.vectorNormal[0];
		//player.vectorEye[1] = player.vectorEye[1] + moving.stepsize*timing.elapsed*player.vectorNormal[1]*0;
		//player.vectorEye[2] = player.vectorEye[2] + moving.stepsize*timing.elapsed*player.vectorNormal[2];
		//player.vectorLook[0] = player.vectorLook[0] + moving.stepsize*timing.elapsed*player.vectorNormal[0];
		//player.vectorLook[1] = player.vectorLook[1] + moving.stepsize*timing.elapsed*player.vectorNormal[1]*0;
		//player.vectorLook[2] = player.vectorLook[2] + moving.stepsize*timing.elapsed*player.vectorNormal[2];
		
		}


}
//-------------------------------------------------------------------------------------------------------
void MoveBackward()
{

	//Normalize Directional Vector
	player.vectorNormal[0] = player.vectorEye[0] - player.vectorLook[0];
	player.vectorNormal[1] = player.vectorEye[1] - player.vectorLook[1];
	player.vectorNormal[2] = player.vectorEye[2] - player.vectorLook[2];
	normalize(player.vectorNormal);
	player.vectorNormal[0] = player.vectorGlobal[0];player.vectorNormal[1] = player.vectorGlobal[1];player.vectorNormal[2] = player.vectorGlobal[2];
	

	//Add Step Forward
	player.vectorEye[0] = player.vectorEye[0] + moving.stepsize*timing.elapsed*player.vectorNormal[0];
	player.vectorEye[1] = player.vectorEye[1] + moving.stepsize*timing.elapsed*player.vectorNormal[1]*0;
	player.vectorEye[2] = player.vectorEye[2] + moving.stepsize*timing.elapsed*player.vectorNormal[2];
	player.vectorLook[0] = player.vectorLook[0] + moving.stepsize*timing.elapsed*player.vectorNormal[0];
	player.vectorLook[1] = player.vectorLook[1] + moving.stepsize*timing.elapsed*player.vectorNormal[1]*0;
	player.vectorLook[2] = player.vectorLook[2] + moving.stepsize*timing.elapsed*player.vectorNormal[2];

	CollisionDetection();
	if (frustum.collision > 0)
		{
		//Undo
		player.vectorEye[0] = player.vectorEye[0] - moving.stepsize*timing.elapsed*player.vectorNormal[0];
		player.vectorEye[1] = player.vectorEye[1] - moving.stepsize*timing.elapsed*player.vectorNormal[1]*0;
		player.vectorEye[2] = player.vectorEye[2] - moving.stepsize*timing.elapsed*player.vectorNormal[2];
		player.vectorLook[0] = player.vectorLook[0] - moving.stepsize*timing.elapsed*player.vectorNormal[0];
		player.vectorLook[1] = player.vectorLook[1] - moving.stepsize*timing.elapsed*player.vectorNormal[1]*0;
		player.vectorLook[2] = player.vectorLook[2] - moving.stepsize*timing.elapsed*player.vectorNormal[2];
		}

}
//-------------------------------------------------------------------------------------------------------
void StrafeLeft()
{
	
	//Normalize Directional Vector
	player.vector[0] = player.vectorEye[0] - player.vectorLook[0];
	player.vector[1] = player.vectorEye[1] - player.vectorLook[1];
	player.vector[2] = player.vectorEye[2] - player.vectorLook[2];
	normalize(player.vector);
	player.vector[0] = player.vectorGlobal[0];player.vector[1] = player.vectorGlobal[1];player.vector[2] = player.vectorGlobal[2];
	angle = atan2(player.vector[0],player.vector[2]);
	player.vector[0] = sin(angle+3.1415925/2);
	player.vector[2] = cos(angle+3.1415925/2);

	player.vectorEye[0] = player.vectorEye[0] - player.vector[0]*timing.elapsed*moving.stepsize;
	player.vectorEye[1] = player.vectorEye[1] - player.vector[1]*timing.elapsed*moving.stepsize*0;
	player.vectorEye[2] = player.vectorEye[2] - player.vector[2]*timing.elapsed*moving.stepsize;
	player.vectorLook[0] = player.vectorLook[0] - player.vector[0]*timing.elapsed*moving.stepsize;
	player.vectorLook[1] = player.vectorLook[1] - player.vector[1]*timing.elapsed*moving.stepsize*0;
	player.vectorLook[2] = player.vectorLook[2] - player.vector[2]*timing.elapsed*moving.stepsize;
	
	CollisionDetection();
	if (frustum.collision > 0)
		{	
		player.vectorEye[0] = player.vectorEye[0] + player.vector[0]*timing.elapsed*moving.stepsize;
		player.vectorEye[1] = player.vectorEye[1] + player.vector[1]*timing.elapsed*moving.stepsize*0;
		player.vectorEye[2] = player.vectorEye[2] + player.vector[2]*timing.elapsed*moving.stepsize;
		player.vectorLook[0] = player.vectorLook[0] + player.vector[0]*timing.elapsed*moving.stepsize;
		player.vectorLook[1] = player.vectorLook[1] + player.vector[1]*timing.elapsed*moving.stepsize*0;
		player.vectorLook[2] = player.vectorLook[2] + player.vector[2]*timing.elapsed*moving.stepsize;
		}

}
//-------------------------------------------------------------------------------------------------------
void StrafeRight()
{

	//Normalize Directional Vector
	player.vector[0] = player.vectorEye[0] - player.vectorLook[0];
	player.vector[1] = player.vectorEye[1] - player.vectorLook[1];
	player.vector[2] = player.vectorEye[2] - player.vectorLook[2];
	normalize(player.vector);
	player.vector[0] = player.vectorGlobal[0];player.vector[1] = player.vectorGlobal[1];player.vector[2] = player.vectorGlobal[2];
	angle = atan2(player.vector[0],player.vector[2]);
	player.vector[0] = sin(angle+3.1415925/2);
	player.vector[2] = cos(angle+3.1415925/2);

	player.vectorEye[0] = player.vectorEye[0] + player.vector[0]*timing.elapsed*moving.stepsize;
	player.vectorEye[1] = player.vectorEye[1] + player.vector[1]*timing.elapsed*moving.stepsize*0;
	player.vectorEye[2] = player.vectorEye[2] + player.vector[2]*timing.elapsed*moving.stepsize;
	player.vectorLook[0] = player.vectorLook[0] + player.vector[0]*timing.elapsed*moving.stepsize;
	player.vectorLook[1] = player.vectorLook[1] + player.vector[1]*timing.elapsed*moving.stepsize*0;
	player.vectorLook[2] = player.vectorLook[2] + player.vector[2]*timing.elapsed*moving.stepsize;
	
	CollisionDetection();
	if (frustum.collision > 0)
		{	
		player.vectorEye[0] = player.vectorEye[0] - player.vector[0]*timing.elapsed*moving.stepsize;
		player.vectorEye[1] = player.vectorEye[1] - player.vector[1]*timing.elapsed*moving.stepsize*0;
		player.vectorEye[2] = player.vectorEye[2] - player.vector[2]*timing.elapsed*moving.stepsize;
		player.vectorLook[0] = player.vectorLook[0] - player.vector[0]*timing.elapsed*moving.stepsize;
		player.vectorLook[1] = player.vectorLook[1] - player.vector[1]*timing.elapsed*moving.stepsize*0;
		player.vectorLook[2] = player.vectorLook[2] - player.vector[2]*timing.elapsed*moving.stepsize;
		}

}
//-------------------------------------------------------------------------------------------------------
