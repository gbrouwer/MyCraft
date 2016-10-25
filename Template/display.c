#include <math.h>           /* C header for any math functions               */
#include <stdio.h>          /* C header for standard I/O                     */
#include <string.h>         /* For String compare                            */
#include <stdlib.h>
#include <GLUT/glut.h>
#include <parameters.h>

//-------------------------------------------------------------------------------------------------------
void drawCube(float sizex, float sizey, float sizez, float posx, float posy, float posz, int ii, int jj, int ll)
{ 

	if (ii == 0 | jj == 0 | ll == 0)
		{
		world.faces[ii][jj][ll][0] = 1;
		world.faces[ii][jj][ll][1] = 1;
		world.faces[ii][jj][ll][2] = 1;
		world.faces[ii][jj][ll][3] = 1;
		world.faces[ii][jj][ll][4] = 1;
		world.faces[ii][jj][ll][5] = 1;
		}
		
		
	if (world.faces[ii][jj][ll][3] > 0)
		{
		nfaces_reduced++;
		glNormal3f( 0.0f, 0.0f, 1.0f);					
		glTexCoord2f(tex.X2[0], tex.Y1[0]);	
		glVertex3f(-sizex+posx, -sizey+posy,  sizez+posz);	
		glTexCoord2f(tex.X2[0], tex.Y2[0]);	
		glVertex3f( sizex+posx, -sizey+posy,  sizez+posz);	
		glTexCoord2f(tex.X1[0], tex.Y2[0]);	
		glVertex3f( sizex+posx,  sizey+posy,  sizez+posz);	
		glTexCoord2f(tex.X1[0], tex.Y1[0]);	
		glVertex3f(-sizex+posx,  sizey+posy,  sizez+posz);	
		}

	if (world.faces[ii][jj][ll][2] > 0)
		{
		nfaces_reduced++;
		glNormal3f( 0.0f, 0.0f,-1.0f);					
		glTexCoord2f(tex.X2[1], tex.Y1[1]);	
		glVertex3f(-sizex+posx, -sizey+posy, -sizez+posz);	
		glTexCoord2f(tex.X1[1], tex.Y1[1]);	
		glVertex3f(-sizex+posx,  sizey+posy, -sizez+posz);	
		glTexCoord2f(tex.X1[1], tex.Y2[1]);	
		glVertex3f( sizex+posx,  sizey+posy, -sizez+posz);	
		glTexCoord2f(tex.X2[1], tex.Y2[1]);	
		glVertex3f( sizex+posx, -sizey+posy, -sizez+posz);	
		}		

	if (world.faces[ii][jj][ll][0] > 0)
		{
		nfaces_reduced++;
		glNormal3f( 0.0f, 1.0f, 0.0f);		
		glTexCoord2f(tex.X2[2], tex.Y1[2]);	
		glVertex3f(-sizex+posx,  sizey+posy, -sizez+posz);
		glTexCoord2f(tex.X1[2], tex.Y1[2]);	
		glVertex3f(-sizex+posx,  sizey+posy,  sizez+posz);	
		glTexCoord2f(tex.X1[2], tex.Y2[2]);	
		glVertex3f( sizex+posx,  sizey+posy,  sizez+posz);
		glTexCoord2f(tex.X2[2], tex.Y2[2]);	
		glVertex3f( sizex+posx,  sizey+posy, -sizez+posz);	
		}
		
	if (world.faces[ii][jj][ll][1] > 0)
		{
		nfaces_reduced++;
		glNormal3f( 0.0f,-1.0f, 0.0f);				
		glTexCoord2f(tex.X1[3], tex.Y1[3]);	
		glVertex3f(-sizex+posx, -sizey+posy, -sizez+posz);
		glTexCoord2f(tex.X1[3], tex.Y2[3]);	
		glVertex3f( sizex+posx, -sizey+posy, -sizez+posz);	
		glTexCoord2f(tex.X2[3], tex.Y2[3]);	
		glVertex3f( sizex+posx, -sizey+posy,  sizez+posz);
		glTexCoord2f(tex.X2[3], tex.Y1[3]);	
		glVertex3f(-sizex+posx, -sizey+posy,  sizez+posz);	
		}
	
	if (world.faces[ii][jj][ll][5] > 0)
		{
		nfaces_reduced++;
		glNormal3f( 1.0f, 0.0f, 0.0f);				
		glTexCoord2f(tex.X2[4], tex.Y1[4]);	
		glVertex3f( sizex+posx, -sizey+posy, -sizez+posz);
		glTexCoord2f(tex.X1[4], tex.Y1[4]);	
		glVertex3f( sizex+posx,  sizey+posy, -sizez+posz);	
		glTexCoord2f(tex.X1[4], tex.Y2[4]);	
		glVertex3f( sizex+posx,  sizey+posy,  sizez+posz);	
		glTexCoord2f(tex.X2[4], tex.Y2[4]);	
		glVertex3f( sizex+posx, -sizey+posy,  sizez+posz);	
		}
			
	if (world.faces[ii][jj][ll][4] > 0)
		{
		nfaces_reduced++;
		glNormal3f(-1.0f, 0.0f, 0.0f);				
		glTexCoord2f(tex.X2[5], tex.Y2[5]);	
		glVertex3f(-sizex+posx, -sizey+posy, -sizez+posz);	
		glTexCoord2f(tex.X2[5], tex.Y1[5]);	
		glVertex3f(-sizex+posx, -sizey+posy,  sizez+posz);	
		glTexCoord2f(tex.X1[5], tex.Y1[5]);	
		glVertex3f(-sizex+posx,  sizey+posy,  sizez+posz);	
		glTexCoord2f(tex.X1[5], tex.Y2[5]);	
		glVertex3f(-sizex+posx,  sizey+posy, -sizez+posz);
		}
}
//-------------------------------------------------------------------------------------------------------
void DrawCrossHair(void)
{

	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glPointSize(12);
	glColor3f(0,0,0);
	glBegin(GL_POINTS);
	glVertex3f(player.vectorLook[0],player.vectorLook[1],player.vectorLook[2]);
	glEnd();
	glPointSize(8);
	glColor3f(1,0,1);
	glBegin(GL_POINTS);
	glVertex3f(player.vectorLook[0],player.vectorLook[1],player.vectorLook[2]);
	glEnd();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glPointSize(12);
	glColor3f(0,0,0);
	glBegin(GL_POINTS);
	glVertex3f(player.vectorLook[0],player.vectorLook[1],player.vectorLook[2]);
	glEnd();
	glPointSize(8);
	glColor3f(1,1,1);
	glBegin(GL_POINTS);
	glVertex3f(player.vectorLook[0],player.vectorLook[1],player.vectorLook[2]);
	glEnd();
	glEnable(GL_DEPTH_TEST);
	

}
//-------------------------------------------------------------------------------------------------------
void DrawFrustrum(void)
{
	glLineWidth(2);
	glColor3f(1,0,0);
	glDisable(GL_LIGHTING);
	
	//Lines of Frustrum
	glPointSize(6);
	glColor3f(1,1,0);
	glBegin(GL_POINTS);
		glVertex3f(frustum.ftl[0],frustum.ftl[1],frustum.ftl[2]);
		glVertex3f(frustum.ntl[0],frustum.ntl[1],frustum.ntl[2]);
		glVertex3f(frustum.fbl[0],frustum.fbl[1],frustum.fbl[2]);
		glVertex3f(frustum.nbl[0],frustum.nbl[1],frustum.nbl[2]);
		glVertex3f(frustum.ftr[0],frustum.ftr[1],frustum.ftr[2]);
		glVertex3f(frustum.ntr[0],frustum.ntr[1],frustum.ntr[2]);
		glVertex3f(frustum.fbr[0],frustum.fbr[1],frustum.fbr[2]);
		glVertex3f(frustum.nbr[0],frustum.nbr[1],frustum.nbr[2]);
	glEnd();

	//Near Plane
	glBegin(GL_LINE_LOOP);
		glVertex3f(frustum.nbl[0],frustum.nbl[1],frustum.nbl[2]);
		glVertex3f(frustum.nbr[0],frustum.nbr[1],frustum.nbr[2]);
		glVertex3f(frustum.ntr[0],frustum.ntr[1],frustum.ntr[2]);
		glVertex3f(frustum.ntl[0],frustum.ntl[1],frustum.ntl[2]);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(frustum.fbl[0],frustum.fbl[1],frustum.fbl[2]);
		glVertex3f(frustum.fbr[0],frustum.fbr[1],frustum.fbr[2]);
		glVertex3f(frustum.ftr[0],frustum.ftr[1],frustum.ftr[2]);
		glVertex3f(frustum.ftl[0],frustum.ftl[1],frustum.ftl[2]);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(frustum.fbl[0],frustum.fbl[1],frustum.fbl[2]);
		glVertex3f(frustum.nbl[0],frustum.nbl[1],frustum.nbl[2]);
		glVertex3f(frustum.fbr[0],frustum.fbr[1],frustum.fbr[2]);
		glVertex3f(frustum.nbr[0],frustum.nbr[1],frustum.nbr[2]);
		glVertex3f(frustum.ftr[0],frustum.ftr[1],frustum.ftr[2]);
		glVertex3f(frustum.ntr[0],frustum.ntr[1],frustum.ntr[2]);
		glVertex3f(frustum.ftl[0],frustum.ftl[1],frustum.ftl[2]);
		glVertex3f(frustum.ntl[0],frustum.ntl[1],frustum.ntl[2]);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(frustum.fbl[0],frustum.fbl[1],frustum.fbl[2]);
		glVertex3f(frustum.nbl[0],frustum.nbl[1],frustum.nbl[2]);
		glVertex3f(frustum.fbr[0],frustum.fbr[1],frustum.fbr[2]);
		glVertex3f(frustum.nbr[0],frustum.nbr[1],frustum.nbr[2]);
		glVertex3f(frustum.ftr[0],frustum.ftr[1],frustum.ftr[2]);
		glVertex3f(frustum.ntr[0],frustum.ntr[1],frustum.ntr[2]);
		glVertex3f(frustum.ftl[0],frustum.ftl[1],frustum.ftl[2]);
		glVertex3f(frustum.ntl[0],frustum.ntl[1],frustum.ntl[2]);
	glEnd();
			
			
	//Draw Plane normals
	glLineWidth(1);
	glColor3f(0,1,0);
	glBegin(GL_POINTS);
	for (i=0;i<6;i++)
		{
		x = i;
		glColor3f(x/6,1-(x/6),0);		
		glVertex3f(frustum.planes[i][3],frustum.planes[i][4],frustum.planes[i][5]);
		glVertex3f(frustum.planes[i][3]+frustum.planes[i][0],frustum.planes[i][4]+frustum.planes[i][1],frustum.planes[i][5]+frustum.planes[i][2]);
		}			
	glEnd();		
	glBegin(GL_LINES);
	for (i=0;i<6;i++)
		{
		x = i;
		glColor3f(x/6,1-(x/6),0);		
		glVertex3f(frustum.planes[i][3],frustum.planes[i][4],frustum.planes[i][5]);
		glVertex3f(frustum.planes[i][3]+frustum.planes[i][0],frustum.planes[i][4]+frustum.planes[i][1],frustum.planes[i][5]+frustum.planes[i][2]);
		}			
	glEnd();				
	glEnable(GL_LIGHTING);


	
}
//-------------------------------------------------------------------------------------------------------
void DrawGrid(void)
{
	int xistart,xiend;
	int zistart,ziend;

	//Viewing Distance
	xi = round(player.vectorLook[0] * 64) + 256;
	zi = round(player.vectorLook[2] * 64) + 256;
	xistart = xi - world.viewdepth;
	if (xistart < 0) {xistart = 0;}
	xiend = xi + world.viewdepth;
	if (xiend > 512) {xiend = 512;}
	zistart = zi - world.viewdepth;
	if (zistart < 0) {zistart = 0;}
	ziend = zi + world.viewdepth;
	if (ziend > 512) {ziend = 512;}


	//Texture mode
	if (drawing.textures == 1)
		{
		glEnable(GL_TEXTURE_2D); 
		if (drawing.texturemode == 1)
			{
			glBindTexture(GL_TEXTURE_2D,tex.IDs[1]);
			}
		else
			{
			glBindTexture(GL_TEXTURE_2D,tex.IDs[2]);
			}
		}
	else
		{glDisable(GL_TEXTURE_2D);}


	//Draw Grid Loop
	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LIGHTING);
	glBegin(GL_QUADS);
	nfaces = 0;
	nfaces_reduced = 0;
	for (i=xistart;i<xiend;i++)
		{
		for (j=zistart;j<ziend;j++)
			{
			for (l=0;l<65;l++)
				{
				if (world.grid[i][j][l] > 0)
					{
					player.vector[0] = ((float)i - 256)/64;
					player.vector[1] = ((float)l - 0.0)/64;
					player.vector[2] = ((float)j - 256)/64;
					PointinFrustrum(player.vector);
					if (frustum.within == 1)
						{
						//World
						if (world.grid[i][j][l] <= 31)
							{
							setTextureAndMaterial(world.grid[i][j][l]);
							drawCube(world.boxsize,world.boxsize,world.boxsize,player.vector[0],player.vector[1],player.vector[2],i,j,l);
							nfaces = nfaces + 6;
							}
						if (world.grid[i][j][l] > 30 & world.grid[i][j][l] < 40 & drawing.trees == 1)
							{
							setTextureAndMaterial(world.grid[i][j][l]);
							drawCube(world.boxsize,world.boxsize,world.boxsize,player.vector[0],player.vector[1],player.vector[2],i,j,l);
							nfaces = nfaces + 6;
							}
						if (world.grid[i][j][l] > 39 & drawing.landmarks == 1)
							{
							setTextureAndMaterial(world.grid[i][j][l]);
							drawCube(world.boxsize,world.boxsize,world.boxsize,player.vector[0],player.vector[1],player.vector[2],i,j,l);
							nfaces = nfaces + 6;
							}
						}
					}
				}
			}
		}
	glEnd();

	//Selected Texture
	glColor3f(0,0,0);
	glLineWidth(2);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glBegin(GL_QUADS);
	if (selected.on == 1 & psycho.on != 1)
		{
		player.vector[0] = ((float)selected.xi - 256)/64;
		player.vector[1] = ((float)selected.yi - 0.0)/64;
		player.vector[2] = ((float)selected.zi - 256)/64;
		setTextureAndMaterial(1);
		drawCube(world.boxsize,world.boxsize,world.boxsize,player.vector[0],player.vector[1],player.vector[2],selected.xi,selected.zi,selected.yi);
		}
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}
//-------------------------------------------------------------------------------------------------------
void DrawClouds(void)
{

	//Draw Cloud
	if (drawing.clouds == 1)
		{
	
		glEnable(GL_BLEND);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDisable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
		tex.ems[0] = 1;
		tex.ems[1] = 1;
		tex.ems[2] = 1;
		tex.ems[3] = 1;
		tex.mat[0] = 1;
		tex.mat[1] = 1;
		tex.mat[2] = 1;
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		for (i=0;i<100;i=i+2)
			{
			drawCube(clouds.size[i][0],clouds.size[i][2],clouds.size[i][1],clouds.position[i][0],clouds.position[i][2],clouds.position[i][1],0,0,0);
			}
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);
		}
}
//-------------------------------------------------------------------------------------------------------
void DrawResponseTargets(void)
{

	float X[3];
	float Y[3];
	float nh = 0.0025;
	float nw = 0.0025;
	float res1[4];
	float res2[4];
	float res3[4];
	float res4[4];
	float distance = 0.1;
	
	glEnable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	tex.ems[0] = 1;
	tex.ems[1] = 1;
	tex.ems[2] = 1;
	tex.ems[3] = 0.5;
	tex.mat[0] = 1;
	tex.mat[1] = 1;
	tex.mat[2] = 1;
	tex.mat[3] = 0.5;
	glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
	glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
	glColor3f(1,1,1);
	glDisable(GL_DEPTH_TEST);

	//Draw Response Targets
	float xyz[3];
	for (i=0;i<3;i++)
		{
		
		//Direction
		val = ((float)i-1);
		val = val / 3.14159275; 
		dist = 1 * cos(frustum.elevation-0.2);
		xyz[0] = player.vectorEye[0] + ((sin(frustum.azimuth+val) * dist) * distance);
		xyz[1] = player.vectorEye[1] + ((1 * sin(frustum.elevation-0.2)) * distance);
		xyz[2] = player.vectorEye[2] + ((cos(frustum.azimuth+val) * dist) * distance);


		//Calculate Normals
		player.vector[0] = (sin(frustum.azimuth+val) * dist) * distance;
		player.vector[1] = (1 * sin(frustum.elevation-0.2)) * distance;
		player.vector[2] = (cos(frustum.azimuth+val) * dist) * distance;
		normalize(player.vector);
		player.vectorNormal[0] = player.vectorGlobal[0];player.vectorNormal[1] = player.vectorGlobal[1];player.vectorNormal[2] = player.vectorGlobal[2];
		Y[0] = (player.vectorNormal[1] * player.vectorUp[2]) - (player.vectorNormal[2] * player.vectorUp[1]);
		Y[1] = (player.vectorNormal[2] * player.vectorUp[0]) - (player.vectorNormal[0] * player.vectorUp[2]);
		Y[2] = (player.vectorNormal[0] * player.vectorUp[1]) - (player.vectorNormal[1] * player.vectorUp[0]);
		normalize(Y);
		Y[0] = player.vectorGlobal[0];Y[1] = player.vectorGlobal[1];Y[2] = player.vectorGlobal[2];
		X[0] = (player.vectorNormal[1] * Y[2]) - (player.vectorNormal[2] * Y[1]);
		X[1] = (player.vectorNormal[2] * Y[0]) - (player.vectorNormal[0] * Y[2]);
		X[2] = (player.vectorNormal[0] * Y[1]) - (player.vectorNormal[1] * Y[0]);
		normalize(X);
		X[0] = player.vectorGlobal[0];X[1] = player.vectorGlobal[1];X[2] = player.vectorGlobal[2];
		
		
		//Edge Points
		res1[0] = xyz[0] - X[0]*nh + Y[0]*nw;
		res1[1] = xyz[1] - X[1]*nh + Y[1]*nw;
		res1[2] = xyz[2] - X[2]*nh + Y[2]*nw;
		res2[0] = xyz[0] + X[0]*nh + Y[0]*nw;
		res2[1] = xyz[1] + X[1]*nh + Y[1]*nw;
		res2[2] = xyz[2] + X[2]*nh + Y[2]*nw;
		res3[0] = xyz[0] - X[0]*nh - Y[0]*nw;
		res3[1] = xyz[1] - X[1]*nh - Y[1]*nw;
		res3[2] = xyz[2] - X[2]*nh - Y[2]*nw;
		res4[0] = xyz[0] + X[0]*nh - Y[0]*nw;
		res4[1] = xyz[1] + X[1]*nh - Y[1]*nw;
		res4[2] = xyz[2] + X[2]*nh - Y[2]*nw;		
		
		//Plot
		glBegin(GL_QUADS);
			glVertex3f(res1[0],res1[1],res1[2]);
			glVertex3f(res3[0],res3[1],res3[2]);
			glVertex3f(res4[0],res4[1],res4[2]);
			glVertex3f(res2[0],res2[1],res2[2]);
		glEnd();
		}
	glEnable(GL_DEPTH_TEST);


}
//-------------------------------------------------------------------------------------------------------
void DrawWorld(void)
{ 
	//Draw World
	if (psycho.on == 0)
		{
		DrawGrid();
		//DrawResponseTargets();
		DrawClouds();
		DrawCrossHair();
		DrawParameters();
		}
	if (psycho.on == 1)
		{
		if (psycho.started == 1)
			{
			DrawGrid();
			DrawClouds();
			DrawCrossHair();
			}
		DrawParameters();
		}

}
//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------
	