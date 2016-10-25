#include <math.h>           /* C header for any math functions               */
#include <stdio.h>          /* C header for standard I/O                     */
#include <string.h>         /* For String compare                            */
#include <stdlib.h>
#include <GLUT/glut.h>	  
#include <parameters.h>

//--------------------------------------------------------------------------------
void InitializeLights(void)
{

	//Sun
	sun.on = 1;
	sun.position[0] = 0.0;
	sun.position[1] = 1.0;
	sun.position[2] = 0.0;
	sun.position[3] = 0.0;
	sun.diffuse[0] = 0.9;
	sun.diffuse[1] = 0.9;
	sun.diffuse[2] = 0.9;
	sun.diffuse[3] = 1.0;
	sun.specular[0] = 0.0;
	sun.specular[1] = 0.0;
	sun.specular[2] = 0.0;
	sun.specular[3] = 0.0;
	sun.ambient[0] = 0.0;
	sun.ambient[1] = 0.0;
	sun.ambient[2] = 0.0;
	sun.ambient[3] = 0.0;
	sun.attenuation_constant = 0.0f;
	sun.attenuation_linear = 1.0f;
	sun.attenuation_quadratic = 1.0f;
	
	
	//Ambiance
	ambiance.on = -1;
	ambiance.position[0] = 0.0;
	ambiance.position[1] = 4.0;
	ambiance.position[2] = 0.0;
	ambiance.position[3] = 0.0;
	ambiance.diffuse[0] = 0.4;
	ambiance.diffuse[1] = 0.4;
	ambiance.diffuse[2] = 0.4;
	ambiance.diffuse[3] = 0.0;
	ambiance.specular[0] = 0.0;
	ambiance.specular[1] = 0.0;
	ambiance.specular[2] = 0.0;
	ambiance.specular[3] = 0.0;
	ambiance.ambient[0] = 0.0;
	ambiance.ambient[1] = 0.0;
	ambiance.ambient[2] = 0.0;
	ambiance.ambient[3] = 0.0;
	ambiance.attenuation_constant = 1.0f;
	ambiance.attenuation_linear = 0.0f;
	ambiance.attenuation_quadratic = 0.0f;


}
//--------------------------------------------------------------------------------
void InitializeAtmospherics(void)
{

	//Atmospherics
	atmosphere.skycolor[0] = 0.63;
	atmosphere.skycolor[1] = 0.77;
	atmosphere.skycolor[2] = 0.91;
	atmosphere.fogcolor[0] = 0.63;
	atmosphere.fogcolor[1] = 0.77;
	atmosphere.fogcolor[2] = 0.91;
	atmosphere.fogon = -1;
	atmosphere.fogdensity = 0.75;
	atmosphere.fogstart = 0.35;
	
}
//--------------------------------------------------------------------------------
void InitializeTiming(void)
{
	
	//Timing
	returntimer();
	timing.base1 = timing.curtime;
	timing.now1 = 0;

}
//--------------------------------------------------------------------------------
void InitializeFrustum(void)
{

	//Viewing and Frustum
	frustum.elevation = 0;
	frustum.azimuth = 0;
	frustum.fov = 35.0f;
	frustum.nearDist = 0.0001f;
	frustum.farDist = 15.0f;
	frustum.aspect = 1.6;
	
}
//--------------------------------------------------------------------------------
void InitializeMovements(void)
{
	
	//Moving
	moving.rotationspeed = 0.05;
	moving.bubble = 0.005;
	moving.hbf = 0;
	moving.headbobbing = 0;
	moving.waiting = 0;
	moving.backward = 0;
	moving.forward = 0;
	moving.strafingright = 0;
	moving.strafingleft = 0;
	moving.rotateright = 0;
	moving.rotateleft = 0;
	moving.rotateup = 0;
	moving.rotatedown = 0;
	moving.jumping = 0;
	moving.collision = 0;
	moving.mouse_sentitivity = 0.001;
	moving.stepsize = 0.0002;	
	moving.jumpspeed_initial = 0.006;
	moving.jumpspeed_decay = 0.05;
	moving.jumpspeed = 0;

}
//--------------------------------------------------------------------------------
void InitializeGravity(void)
{
	gravitation.on = -1;
	gravitation.initial = 0.0001;
	gravitation.decay = 1.0000;
	gravitation.collision = 0;
}
//--------------------------------------------------------------------------------
void InitializeGraphics(void)
{

	drawing.trees = 1;
	drawing.clouds = -1;
	drawing.nClouds = 10;
	drawing.textures = 1;

}
//--------------------------------------------------------------------------------
void InitializeWorld(void)
{

	//Init World
	world.boxsize = 0.00781;
	world.boxradius = sqrt(world.boxsize*world.boxsize*2);
	world.viewdepth = 120;
	
}
//--------------------------------------------------------------------------------
void InitializeInfo(void)
{
	
	//Information
	info.currentframe = 0;
	info.display = 1;
	info.executable = 0;

}
//--------------------------------------------------------------------------------
void InitializePsychophysics(void)
{
	float rAzimuth;
	rAzimuth = rand()%360;
	rAzimuth = rAzimuth / 360 * 2 * 3.14159275;
	
	//Start Trials
	curTrial++;
	if (curTrial > 24)
		{exit(0);}
	psycho.on = 0;
	atmosphere.fogon = 1;
	drawing.trees = 1;
	drawing.landmarks = 1;
	drawing.clouds = 1;
	drawing.textures = 1;
	drawing.texturemode = -1;
	gravitation.on = 1;
	psycho.stop = 0;
	psycho.started = 0;
	psycho.curSample = 0;
	psycho.startPosition[0] = psycho.startLocations[curTrial-1][0];
	psycho.startPosition[1] = psycho.startLocations[curTrial-1][1];
	psycho.startPosition[2] = psycho.startLocations[curTrial-1][2];
	psycho.startAzimuth = rAzimuth;
	psycho.startElevation = 0;
	frustum.elevation = psycho.startElevation;
	frustum.azimuth = psycho.startAzimuth;

	//Clear Trace	
	for (i=0;i<1000000;i++)
		{
		psycho.curPosition[i][0] = 0;
		psycho.curPosition[i][1] = 0;
		psycho.curPosition[i][2] = 0;
		psycho.curDirection[i][0] = 0;
		psycho.curDirection[i][1] = 0;
		psycho.curDirection[i][2] = 0;
		psycho.curAzimuth[i] = 0;
		psycho.curElevation[i] = -999;
	
		}
	
}
//--------------------------------------------------------------------------------
void InitializeParameters(void)
{

	//Initialize
	InitializeLights();
	InitializeAtmospherics();
	InitializeTiming();
	InitializeFrustum();
	InitializeMovements();
	InitializeGravity();
	InitializeGraphics();
	InitializeWorld();
	InitializeInfo();
	InitializePsychophysics();
	CreateClouds();

}
//--------------------------------------------------------------------------------
void DrawParameters(void)
{
	//Draw Current Parameters
	if (info.display == 1)
		{
		//Save 3D Matrices
		glDisable(GL_LIGHTING);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glDisable(GL_DEPTH_TEST);

		//Switch to 2D
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		GLint m_viewport[4];
		glGetIntegerv( GL_VIEWPORT, m_viewport );
		glOrtho(0,m_viewport[2],0,m_viewport[3],0,1);

		if (psycho.on == 1 & psycho.started == 0)
			{
			if (psycho.started == 0)
				{
				sprintf(info.information_string,"Waiting to continue....");
				sprintf(info.continue_string,"Press backtick to start...");
				glColor3f(1,1,1);
				glRasterPos3f((m_viewport[2]/2)-100,m_viewport[3]/2,0);
				for (i = 0; i < strlen(info.information_string); i++)
					{glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, info.information_string[i]);}
				glColor3f(1,1,1);
				if (gravitation.collision > 0)
					{
					glRasterPos3f((m_viewport[2]/2)-100,(m_viewport[3]/2)-25,0);
					for (i = 0; i < strlen(info.continue_string); i++)
						{glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, info.continue_string[i]);}
					}
				}			
			}
		if (psycho.on == 0)
			{
			//Current Location in grid
			xi = round((player.vectorEye[0] * 64) + 256);
			yi = round((player.vectorEye[1] * 64) + 0);
			zi = round((player.vectorEye[2] * 64) + 256);


			//Fill Strings
			sprintf(info.position_string,"Position : %2.4f %2.4f %2.4f",player.vectorEye[0],player.vectorEye[1],player.vectorEye[2]);
			sprintf(info.block_string,"Block : %d %d %d",xi,yi,zi);
			sprintf(info.direction_string,"Direction : %2.4f %2.4f %2.4f",player.vectorLook[0],player.vectorLook[1],player.vectorLook[2]);
			sprintf(info.selected_string,"Selected : %d %d %d",selected.zi+1,selected.xi+1,selected.yi+1);
			sprintf(info.framerate_string,"Framerate : %2.4f fps",1000/timing.elapsed);
			sprintf(info.faces_string,"Number of Faces : %d , reduced : %d",nfaces,nfaces_reduced);
			sprintf(info.faces_string,"Azimuth: %f , Elevation: %f",frustum.azimuth,frustum.elevation);



			//Draw Strings
			glColor3f(1,1,1);
			glRasterPos3f(10,m_viewport[3]-20,0);
			for (i = 0; i < strlen(info.position_string); i++)
				{glutBitmapCharacter( GLUT_BITMAP_HELVETICA_12, info.position_string[i]);}
			glRasterPos3f(10,m_viewport[3]-40,0);
			for (i = 0; i < strlen(info.block_string); i++)
				{glutBitmapCharacter( GLUT_BITMAP_HELVETICA_12, info.block_string[i]);}
			glRasterPos3f(10,m_viewport[3]-60,0);
			for (i = 0; i < strlen(info.direction_string); i++)
				{glutBitmapCharacter( GLUT_BITMAP_HELVETICA_12, info.direction_string[i]);}
			glRasterPos3f(10,m_viewport[3]-80,0);
			for (i = 0; i < strlen(info.selected_string); i++)
				{glutBitmapCharacter( GLUT_BITMAP_HELVETICA_12, info.selected_string[i]);}
			glRasterPos3f(10,m_viewport[3]-100,0);
			for (i = 0; i < strlen(info.framerate_string); i++)
				{glutBitmapCharacter( GLUT_BITMAP_HELVETICA_12, info.framerate_string[i]);}
			glRasterPos3f(10,m_viewport[3]-120,0);
			for (i = 0; i < strlen(info.faces_string); i++)
				{glutBitmapCharacter( GLUT_BITMAP_HELVETICA_12, info.faces_string[i]);}
			glRasterPos3f(10,m_viewport[3]-140,0);
			for (i = 0; i < strlen(info.azimuthelevationstring); i++)
				{glutBitmapCharacter( GLUT_BITMAP_HELVETICA_12, info.azimuthelevationstring[i]);}
			}
			
		//Switch back
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		}

}
//--------------------------------------------------------------------------------
void InitializeFaces(void)
{
	
	fprintf(stderr,"Determining which faces need to be drawn\n");
	for (i=1;i<512;i++)
		{
		for (j=1;j<512;j++)
			{
			for (l=1;l<64;l++)
				{
				if (world.grid[i][j][l] > 0)
					{
					world.faces[i][j][l][0] = 1;
					world.faces[i][j][l][1] = 1;
					world.faces[i][j][l][2] = 1;
					world.faces[i][j][l][3] = 1;
					world.faces[i][j][l][4] = 1;
					world.faces[i][j][l][5] = 1;
					if (world.grid[i][j][l-1] > 0)
						{
						//world.faces[i][j][l][0] = 0;
						}
					if (world.grid[i][j][l+1] > 0)
						{
						//world.faces[i][j][l][1] = 0;
						}
					if (world.grid[i][j-1][l] > 0)
						{
						world.faces[i][j][l][2] = 0;
						}
					if (world.grid[i][j+1][l] > 0)
						{
						world.faces[i][j][l][3] = 0;
						}
					if (world.grid[i-1][j][l] > 0)
						{
						world.faces[i][j][l][4] = 0;
						}
					if (world.grid[i+1][j][l] > 0)
						{
						world.faces[i][j][l][5] = 0;
						}
					}
				}
			}
		}

}
//--------------------------------------------------------------------------------
