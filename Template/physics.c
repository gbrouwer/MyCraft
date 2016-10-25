#include <math.h>          
#include <stdio.h>         
#include <string.h>       
#include <stdlib.h>
#include <GLUT/glut.h>	  
#include <parameters.h>


//-------------------------------------------------------------------------------------------------------
void NearestNeigbor()
{

	//Normalize Directional Vector
	player.vector[0] = player.vectorEye[0] - player.vectorLook[0];
	player.vector[1] = player.vectorEye[1] - player.vectorLook[1];
	player.vector[2] = player.vectorEye[2] - player.vectorLook[2];
	normalize(player.vector);
	player.vector[0] = player.vectorGlobal[0];player.vector[1] = player.vectorGlobal[1];player.vector[2] = player.vectorGlobal[2];

	//Find Closest Block Intersection 
	selected.xi = 0;
	selected.yi = 0;
	selected.zi = 0;
	selected.on = 0;
	angle = atan2(player.vector[0],player.vector[2]);
	for (i=0;i<33;i++)
		{
		val = (float) i / 33;
		val = (1 - val) * 0.02;
		xv = frustum.fc[0]*val + player.vectorEye[0]*(1-val);
		yv = frustum.fc[1]*val + ((1-frustum.collision)*moving.hbf)+player.vectorEye[1]*(1-val);
		zv = frustum.fc[2]*val + player.vectorEye[2]*(1-val);
		xi = round(xv * 64) + 256;
		yi = round(yv * 64) + 0.0;
		zi = round(zv * 64) + 256;
		if (world.grid[xi][zi][yi] > 0)
			{
			selected.xi = xi;
			selected.yi = yi;
			selected.zi = zi;
			selected.on = 1;
			}
		}

}
//-------------------------------------------------------------------------------------------------------
void EraseBlock()
{

	//Remove Block
	if (xi < 1000 & yi > 0)
		{
		world.grid[xi][zi][yi-1] = 42;
		world.grid[xi][zi][yi]= 0;
		InitializeFaces();
		}
		
		
}
//-------------------------------------------------------------------------------------------------------
void CollisionDetection()
{
	
	//Normalize Directional Vector
	player.vectorNormal[0] = player.vectorEye[0] - player.vectorLook[0];
	player.vectorNormal[1] = player.vectorEye[1] - player.vectorLook[1];
	player.vectorNormal[2] = player.vectorEye[2] - player.vectorLook[2];
	normalize(player.vectorNormal);
	player.vectorNormal[0] = player.vectorGlobal[0];player.vectorNormal[1] = player.vectorGlobal[1];player.vectorNormal[2] = player.vectorGlobal[2];
	
	
	//Bumper Direction
	if (moving.forward == 1)
		{angle = atan2(player.vectorNormal[0],player.vectorNormal[2]);}
	if (moving.backward == 1)
		{angle = -3.14159275 + atan2(player.vectorNormal[0],player.vectorNormal[2]);}
	if (moving.strafingright == 1)
		{angle = (-3.14159275/2) + atan2(player.vectorNormal[0],player.vectorNormal[2]);}
	if (moving.strafingleft == 1)
		{angle = atan2(player.vectorNormal[0],player.vectorNormal[2]) + 3.14159275/2;}
	if (moving.forward == 1 & moving.strafingright == 1)
		{angle = -3.14159275/4 + atan2(player.vectorNormal[0],player.vectorNormal[2]);}
	if (moving.forward == 1 & moving.strafingleft == 1)
		{angle = atan2(player.vectorNormal[0],player.vectorNormal[2]) + 3.14159275/4;}
	if (moving.backward == 1 & moving.strafingright == 1)
		{angle = 3.14159275*1.25 + atan2(player.vectorNormal[0],player.vectorNormal[2]);}
	if (moving.backward == 1 & moving.strafingleft == 1)
		{angle = atan2(player.vectorNormal[0],player.vectorNormal[2]) + (3.14159275/2) + (3.14159275/4);}




	//Determine Bumper Contact
	frustum.collision = 0;
	for (i=0;i<17;i++)
		{
		val = angle + ((((float)i-8) / 16) * 3.14159275/2);
		x = sin(val)*moving.bubble;
		y = cos(val)*moving.bubble;
		xv = player.vectorEye[0]-x;
		yv = player.vectorEye[1];
		zv = player.vectorEye[2]-y;
		xi = round(xv * 64) + 256;
		yi = round(yv * 64) + 0;
		zi = round(zv * 64) + 256;
		if (world.grid[xi][zi][yi-2] > 0)
			{
			frustum.collision = 1;
			}
		}
		
	 
	 

}
//-------------------------------------------------------------------------------------------------------
void Gravity()
{

	player.vectorEye[1] = player.vectorEye[1] - (gravitation.initial * timing.elapsed);
	player.vectorLook[1] = player.vectorLook[1] - (gravitation.initial * timing.elapsed);
	xi = round((player.vectorEye[0] * 64) + 256);
	yi = round((player.vectorEye[1] * 64) + 0);
	zi = round((player.vectorEye[2] * 64) + 256);
	if (world.grid[xi][zi][yi-2] > 0)
		{
		gravitation.collision = 1;
		moving.jumping = 0;
		player.vectorEye[1] = player.vectorEye[1] + (gravitation.initial * timing.elapsed);
		player.vectorLook[1] = player.vectorLook[1] + (gravitation.initial * timing.elapsed);
		}
		

}
//-------------------------------------------------------------------------------------------------------
void CalculateFrustrum()
{

	float X[3];
	float Y[3];
	

	//Calculate height and width of far and near frustrum planes
	frustum.nh = frustum.nearDist * (float)tan(frustum.fov / 180 * 3.14159275 * 0.5);;
	frustum.nw = frustum.nh * frustum.aspect; 
	frustum.fh = frustum.farDist  * (float)tan(frustum.fov / 180 * 3.14159275 * 0.5);;
	frustum.fw = frustum.fh * frustum.aspect;

	
	//Get Vector and Normalize
	player.vectorNormal[0] = player.vectorEye[0] - player.vectorLook[0];
	player.vectorNormal[1] = player.vectorEye[1] - player.vectorLook[1];
	player.vectorNormal[2] = player.vectorEye[2] - player.vectorLook[2];
	normalize(player.vectorNormal);
	player.vectorNormal[0] = player.vectorGlobal[0];player.vectorNormal[1] = player.vectorGlobal[1];player.vectorNormal[2] = player.vectorGlobal[2];
	

	//Center Points of near and far frustrum planes
	frustum.nc[0] = player.vectorEye[0] - player.vectorNormal[0]*frustum.nearDist;
	frustum.nc[1] = player.vectorEye[1] - player.vectorNormal[1]*frustum.nearDist;
	frustum.nc[2] = player.vectorEye[2] - player.vectorNormal[2]*frustum.nearDist;
	frustum.fc[0] = player.vectorEye[0] - player.vectorNormal[0]*frustum.farDist;
	frustum.fc[1] = player.vectorEye[1] - player.vectorNormal[1]*frustum.farDist;
	frustum.fc[2] = player.vectorEye[2] - player.vectorNormal[2]*frustum.farDist;
	
	
	//Stage 1
	Y[0] = (player.vectorNormal[1] * player.vectorUp[2]) - (player.vectorNormal[2] * player.vectorUp[1]);
	Y[1] = (player.vectorNormal[2] * player.vectorUp[0]) - (player.vectorNormal[0] * player.vectorUp[2]);
	Y[2] = (player.vectorNormal[0] * player.vectorUp[1]) - (player.vectorNormal[1] * player.vectorUp[0]);
	normalize(Y);
	Y[0] = player.vectorGlobal[0];Y[1] = player.vectorGlobal[1];Y[2] = player.vectorGlobal[2];


	//Stage 2
	X[0] = (player.vectorNormal[1] * Y[2]) - (player.vectorNormal[2] * Y[1]);
	X[1] = (player.vectorNormal[2] * Y[0]) - (player.vectorNormal[0] * Y[2]);
	X[2] = (player.vectorNormal[0] * Y[1]) - (player.vectorNormal[1] * Y[0]);
	normalize(X);
	X[0] = player.vectorGlobal[0];X[1] = player.vectorGlobal[1];X[2] = player.vectorGlobal[2];


	//Near Frustrum Plane
	frustum.ntl[0] = frustum.nc[0] - X[0]*frustum.nh + Y[0]*frustum.nw;
	frustum.ntl[1] = frustum.nc[1] - X[1]*frustum.nh + Y[1]*frustum.nw;
	frustum.ntl[2] = frustum.nc[2] - X[2]*frustum.nh + Y[2]*frustum.nw;
	frustum.ntr[0] = frustum.nc[0] + X[0]*frustum.nh + Y[0]*frustum.nw;
	frustum.ntr[1] = frustum.nc[1] + X[1]*frustum.nh + Y[1]*frustum.nw;
	frustum.ntr[2] = frustum.nc[2] + X[2]*frustum.nh + Y[2]*frustum.nw;
	frustum.nbl[0] = frustum.nc[0] - X[0]*frustum.nh - Y[0]*frustum.nw;
	frustum.nbl[1] = frustum.nc[1] - X[1]*frustum.nh - Y[1]*frustum.nw;
	frustum.nbl[2] = frustum.nc[2] - X[2]*frustum.nh - Y[2]*frustum.nw;
	frustum.nbr[0] = frustum.nc[0] + X[0]*frustum.nh - Y[0]*frustum.nw;
	frustum.nbr[1] = frustum.nc[1] + X[1]*frustum.nh - Y[1]*frustum.nw;
	frustum.nbr[2] = frustum.nc[2] + X[2]*frustum.nh - Y[2]*frustum.nw;

	//Far Frustrum Plane
	frustum.ftl[0] = frustum.fc[0] - X[0]*frustum.fh + Y[0]*frustum.fw;
	frustum.ftl[1] = frustum.fc[1] - X[1]*frustum.fh + Y[1]*frustum.fw;
	frustum.ftl[2] = frustum.fc[2] - X[2]*frustum.fh + Y[2]*frustum.fw;
	frustum.ftr[0] = frustum.fc[0] + X[0]*frustum.fh + Y[0]*frustum.fw;
	frustum.ftr[1] = frustum.fc[1] + X[1]*frustum.fh + Y[1]*frustum.fw;
	frustum.ftr[2] = frustum.fc[2] + X[2]*frustum.fh + Y[2]*frustum.fw;
	frustum.fbl[0] = frustum.fc[0] - X[0]*frustum.fh - Y[0]*frustum.fw;
	frustum.fbl[1] = frustum.fc[1] - X[1]*frustum.fh - Y[1]*frustum.fw;
	frustum.fbl[2] = frustum.fc[2] - X[2]*frustum.fh - Y[2]*frustum.fw;
	frustum.fbr[0] = frustum.fc[0] + X[0]*frustum.fh - Y[0]*frustum.fw;
	frustum.fbr[1] = frustum.fc[1] + X[1]*frustum.fh - Y[1]*frustum.fw;
	frustum.fbr[2] = frustum.fc[2] + X[2]*frustum.fh - Y[2]*frustum.fw;



	//Calculate Normals
	calculateNormal(frustum.ftl,frustum.ftr,frustum.fbr);
	normalize(player.vectorNormal);
	player.vectorNormal[0] = player.vectorGlobal[0];
	player.vectorNormal[1] = player.vectorGlobal[1];
	player.vectorNormal[2] = player.vectorGlobal[2];
	frustum.planes[0][0] = player.vectorNormal[0];
	frustum.planes[0][1] = player.vectorNormal[1];
	frustum.planes[0][2] = player.vectorNormal[2];
	frustum.planes[0][3] = (frustum.ftl[0] + frustum.ftr[0] + frustum.fbl[0] + frustum.fbr[0]) * 0.25;
	frustum.planes[0][4] = (frustum.ftl[1] + frustum.ftr[1] + frustum.fbl[1] + frustum.fbr[1]) * 0.25;
	frustum.planes[0][5] = (frustum.ftl[2] + frustum.ftr[2] + frustum.fbl[2] + frustum.fbr[2]) * 0.25;
	frustum.planes[0][6] = -(frustum.planes[0][0]*frustum.ftl[0] + frustum.planes[0][1]*frustum.ftl[1] + frustum.planes[0][2]*frustum.ftl[2]);

	calculateNormal(frustum.ntr,frustum.nbr,frustum.fbr);
	normalize(player.vectorNormal);
	player.vectorNormal[0] = player.vectorGlobal[0];
	player.vectorNormal[1] = player.vectorGlobal[1];
	player.vectorNormal[2] = player.vectorGlobal[2];
	frustum.planes[1][0] = player.vectorNormal[0];
	frustum.planes[1][1] = player.vectorNormal[1];
	frustum.planes[1][2] = player.vectorNormal[2];
	frustum.planes[1][3] = (frustum.ntr[0] + frustum.nbr[0] + frustum.fbr[0] + frustum.ftr[0]) * 0.25;
	frustum.planes[1][4] = (frustum.ntr[1] + frustum.nbr[1] + frustum.fbr[1] + frustum.ftr[1]) * 0.25;
	frustum.planes[1][5] = (frustum.ntr[2] + frustum.nbr[2] + frustum.fbr[2] + frustum.ftr[2]) * 0.25;
	frustum.planes[1][6] = -(frustum.planes[1][0]*frustum.ntr[0] + frustum.planes[1][1]*frustum.ntr[1] + frustum.planes[1][2]*frustum.ntr[2]);

	calculateNormal(frustum.ntl,frustum.fbl,frustum.nbl);
	normalize(player.vectorNormal);
	player.vectorNormal[0] = player.vectorGlobal[0];
	player.vectorNormal[1] = player.vectorGlobal[1];
	player.vectorNormal[2] = player.vectorGlobal[2];
	frustum.planes[2][0] = player.vectorNormal[0];
	frustum.planes[2][1] = player.vectorNormal[1];
	frustum.planes[2][2] = player.vectorNormal[2];
	frustum.planes[2][3] = (frustum.ntl[0] + frustum.nbl[0] + frustum.fbl[0] + frustum.ftl[0]) * 0.25;
	frustum.planes[2][4] = (frustum.ntl[1] + frustum.nbl[1] + frustum.fbl[1] + frustum.ftl[1]) * 0.25;
	frustum.planes[2][5] = (frustum.ntl[2] + frustum.nbl[2] + frustum.fbl[2] + frustum.ftl[2]) * 0.25;
	frustum.planes[2][6] = -(player.vectorNormal[0]*frustum.ntl[0] + player.vectorNormal[1]*frustum.ntl[1] + player.vectorNormal[2]*frustum.ntl[2]);

	calculateNormal(frustum.ftr,frustum.ftl,frustum.ntl);
	normalize(player.vectorNormal);
	player.vectorNormal[0] = player.vectorGlobal[0];
	player.vectorNormal[1] = player.vectorGlobal[1];
	player.vectorNormal[2] = player.vectorGlobal[2];
	frustum.planes[3][0] = player.vectorNormal[0];
	frustum.planes[3][1] = player.vectorNormal[1];
	frustum.planes[3][2] = player.vectorNormal[2];
	frustum.planes[3][3] = (frustum.ftr[0] + frustum.ftl[0] + frustum.ntl[0] + frustum.ntr[0]) * 0.25;
	frustum.planes[3][4] = (frustum.ftr[1] + frustum.ftl[1] + frustum.ntl[1] + frustum.ntr[1]) * 0.25;
	frustum.planes[3][5] = (frustum.ftr[2] + frustum.ftl[2] + frustum.ntl[2] + frustum.ntr[2]) * 0.25;
	frustum.planes[3][6] = -(player.vectorNormal[0]*frustum.ftr[0] + player.vectorNormal[1]*frustum.ftr[1] + player.vectorNormal[2]*frustum.ftr[2]);

	calculateNormal(frustum.fbr,frustum.nbl,frustum.fbl);
	normalize(player.vectorNormal);
	player.vectorNormal[0] = player.vectorGlobal[0];
	player.vectorNormal[1] = player.vectorGlobal[1];
	player.vectorNormal[2] = player.vectorGlobal[2];
	frustum.planes[4][0] = player.vectorNormal[0];
	frustum.planes[4][1] = player.vectorNormal[1];
	frustum.planes[4][2] = player.vectorNormal[2];
	frustum.planes[4][3] = (frustum.fbr[0] + frustum.fbl[0] + frustum.nbl[0] + frustum.nbr[0]) * 0.25;
	frustum.planes[4][4] = (frustum.fbr[1] + frustum.fbl[1] + frustum.nbl[1] + frustum.nbr[1]) * 0.25;
	frustum.planes[4][5] = (frustum.fbr[2] + frustum.fbl[2] + frustum.nbl[2] + frustum.nbr[2]) * 0.25;
	frustum.planes[4][6] = -(player.vectorNormal[0]*frustum.fbr[0] + player.vectorNormal[1]*frustum.fbr[1] + player.vectorNormal[2]*frustum.fbr[2]);

	calculateNormal(frustum.ntl,frustum.nbr,frustum.ntr);
	normalize(player.vectorNormal);
	player.vectorNormal[0] = player.vectorGlobal[0];
	player.vectorNormal[1] = player.vectorGlobal[1];
	player.vectorNormal[2] = player.vectorGlobal[2];
	frustum.planes[5][0] = player.vectorNormal[0];
	frustum.planes[5][1] = player.vectorNormal[1];
	frustum.planes[5][2] = player.vectorNormal[2];
	frustum.planes[5][3] = (frustum.ntl[0] + frustum.ntr[0] + frustum.nbr[0] + frustum.nbl[0]) * 0.25;
	frustum.planes[5][4] = (frustum.ntl[1] + frustum.ntr[1] + frustum.nbr[1] + frustum.nbl[1]) * 0.25;
	frustum.planes[5][5] = (frustum.ntl[2] + frustum.ntr[2] + frustum.nbr[2] + frustum.nbl[2]) * 0.25;
	frustum.planes[5][6] = -(player.vectorNormal[0]*frustum.ntl[0] + player.vectorNormal[1]*frustum.ntl[1] + player.vectorNormal[2]*frustum.ntl[2]);

		
}
//-------------------------------------------------------------------------------------------------------
void PointinFrustrum(float point[3])
{

	//Determine Location of Point is within the frustum
	frustum.within = 0;
	if ((frustum.planes[0][0]*point[0] + frustum.planes[0][1]*point[1] + frustum.planes[0][2]*point[2] + frustum.planes[0][6]) > -world.boxradius*2)
		{
		if ((frustum.planes[1][0]*point[0] + frustum.planes[1][1]*point[1] + frustum.planes[1][2]*point[2] + frustum.planes[1][6]) > -world.boxradius*2)
			{
			if ((frustum.planes[2][0]*point[0] + frustum.planes[2][1]*point[1] + frustum.planes[2][2]*point[2] + frustum.planes[2][6]) > -world.boxradius*2)
				{
				if ((frustum.planes[3][0]*point[0] + frustum.planes[3][1]*point[1] + frustum.planes[3][2]*point[2] + frustum.planes[3][6]) > -world.boxradius*2)
					{
					if ((frustum.planes[4][0]*point[0] + frustum.planes[4][1]*point[1] + frustum.planes[4][2]*point[2] + frustum.planes[4][6]) > -world.boxradius*2)
						{
						if ((frustum.planes[5][0]*point[0] + frustum.planes[5][1]*point[1] + frustum.planes[5][2]*point[2] + frustum.planes[5][6]) > -world.boxradius*2)
							{
							frustum.within = 1;
							}
						}
					}
				}
			}
		}
}	
//-------------------------------------------------------------------------------------------------------
