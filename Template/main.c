#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GLUT/glut.h>
#include "memory.h"           
#include <math.h>
#include <parameters.h>

//Variables
extern float x,y,z,dist;
extern float angle;
extern int i,j,l,m;

int dumpscreen = 0;

const double Xmin = -1.0, Xmax = 4.0;
const double Ymin = -1.0, Ymax = 4.0;

//-------------------------------------------------------------------------------------------------------
void returntimer(void)
{
	unsigned long i;
	struct timeval CurrentTime;
	gettimeofday(&CurrentTime,NULL);
	i = CurrentTime.tv_sec;
	i *= 1000000;   
	i += CurrentTime.tv_usec;
	i /= 1000;    
	timing.curtime = i;
}
//-------------------------------------------------------------------------------------------------------
void Init(void)
{
	
	InitializePosition();
	glEnable(GL_DEPTH_TEST);
	glClearColor(atmosphere.skycolor[0],atmosphere.skycolor[1],atmosphere.skycolor[2],1);
	glShadeModel(GL_FLAT);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glHint(GL_POLYGON_SMOOTH_HINT,GL_NICEST);
	DefineLights();
	DefineAtmospherics();
	gluLookAt(player.vectorEye[0],player.vectorEye[1],player.vectorEye[2],player.vectorLook[0],player.vectorLook[1],player.vectorLook[2],player.vectorUp[0],player.vectorUp[1],player.vectorUp[2]);

}
//-------------------------------------------------------------------------------------------------------
void display ( void )
{
	
	//Display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	DrawWorld();
	glFlush();
	glFinish();
	glutSwapBuffers();
	glutPostRedisplay();
	
}
//-------------------------------------------------------------------------------------------------------
static void key ( unsigned char key, int x, int y )
{	
	//Key presses
    fprintf(stderr,"%d\n",key);
	switch ( key ) {
		case 27  :
		exit (0) ;
	case '`':
		if (psycho.started == 0 & psycho.on == 1)
			{
			psycho.started = 1;
			psycho.curSample = 0;
			}
		break;
	case 32:
		if (moving.jumping == 0)
			{moving.jumpspeed = moving.jumpspeed_initial;moving.jumping = 1;}	
		break;
	case 'h':
		dumpscreen = 1;
		break;	
 	case 'w':
		moving.backward = 0;
		moving.forward = 1;
		break;
 	case 's':
		moving.backward = 1;
		moving.forward = 0;
		break;
	case 'd':
	 	moving.strafingleft = 0;
	 	moving.strafingright = 1;
		break;
	case 'a':
	 	moving.strafingleft = 1;
	 	moving.strafingright = 0;
		break;
	case 'j':
		moving.rotateleft = 1;
		moving.rotateright = 0;
		break;
	case 'l':
		moving.rotateleft = 0;
		moving.rotateright = 1;
		break;
	case 'k':
		moving.rotateup = 0;
		moving.rotatedown = 1;
		break;
	case 'i':
		moving.rotateup = 1;
		moving.rotatedown = 0;
		break;
	case 'm':
		if (psycho.on != 1)
			{
			drawing.texturemode = -drawing.texturemode;
			}
		break;
	case 't':
		if (psycho.on != 1)
			{
			drawing.trees = -drawing.trees;
			}
		break;
	case 'y':
		if (psycho.on != 1)
			{
			drawing.landmarks = -drawing.landmarks;
			}
		break;
	case 'g':
		if (psycho.on != 1)
			{
			gravitation.on = -gravitation.on;
			}
		break;
	case 'o':
		if (psycho.on != 1)
			{
			sun.on = -sun.on;
			DefineLights();
			}
		break;
	case 'p':
		if (psycho.on != 1)
			{
			ambiance.on = -ambiance.on;
			DefineLights();
			}
		break;
	case 'b':
		if (psycho.on != 1)
			{
			xi = selected.xi;
			yi = selected.yi;
			zi = selected.zi;
			EraseBlock();
			}
		break;
	case 'n':
		if (psycho.on != 1)
			{
			drawing.textures = -drawing.textures;
			}
		break;
	case 'r':
		if (psycho.on != 1)
			{
			WriteWorld();
			}
		break;
	case 'v':
		if (psycho.on != 1)
			{
			drawing.clouds = -drawing.clouds;
			}
		break;
	case 'f':
		if (psycho.on != 1)
			{
			atmosphere.fogon = -atmosphere.fogon;
			DefineAtmospherics();
			}
		break;
	case 'u':
		psycho.stop = 1;
		break;
		}
			
}
//-------------------------------------------------------------------------------------------------------
static void keyUp ( unsigned char key, int x, int y )
{
	//Key presses	
	moving.headbobbing = 0;
	switch ( key ) {
 	case 'w':
		moving.backward = 0;
		moving.forward = 0;
		break;
 	case 's':
		moving.backward = 0;
		moving.forward = 0;
		break;
	case 'a':
	 	moving.strafingleft = 0;
	 	moving.strafingright = 0;
		break;
	case 'd':
	 	moving.strafingleft = 0;
	 	moving.strafingright = 0;
		break;
	case 'j':
		moving.rotateleft = 0;
		moving.rotateright = 0;
		break;
	case 'l':
		moving.rotateleft = 0;
		moving.rotateright = 0;
		break;
	case 'k':
		moving.rotateup = 0;
		moving.rotatedown = 0;
		break;
	case 'i':
		moving.rotateup = 0;
		moving.rotatedown = 0;
		break;
		}
			

}
//-------------------------------------------------------------------------------------------------------
void myReshape ( int w, int h )
{
	double scale, center;
	double windowXmin, windowXmax, windowYmin, windowYmax;
	
	w = (w==0) ? 1 : w;
	h = (h==0) ? 1 : h;
	if ( (Xmax-Xmin)/w < (Ymax-Ymin)/h ) {
		scale = ((Ymax-Ymin)/h)/((Xmax-Xmin)/w);
		center = (Xmax+Xmin)/2;
		windowXmin = center - (center-Xmin)*scale;
		windowXmax = center + (Xmax-center)*scale;
		windowYmin = Ymin;
		windowYmax = Ymax;
	}
	else {
		scale = ((Xmax-Xmin)/w)/((Ymax-Ymin)/h);
		center = (Ymax+Ymin)/2;
		windowYmin = center - (center-Ymin)*scale;
		windowYmax = center + (Ymax-center)*scale;
		windowXmin = Xmin;
		windowXmax = Xmax;
	}
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
	gluPerspective(frustum.fov, (float)w/(float)h, frustum.nearDist,frustum.farDist);
	glMatrixMode( GL_MODELVIEW );
    glViewport( 0, 0, w, h );		
}
//-------------------------------------------------------------------------------------------------------
void glutIdle(void)
{
	if (dumpscreen == 1)
		{	
		ScreenDump();
		}

	//Get Current Time
	returntimer();
	timing.now1 = timing.curtime - timing.base1;
	timing.now2 = timing.curtime - timing.base2;
	timing.elapsed = timing.now1;
	
	//Record Trial
	if (psycho.on == 1 & psycho.started == 1)
		{
		psycho.curPosition[psycho.curSample][0] = player.vectorEye[0];
		psycho.curPosition[psycho.curSample][1] = player.vectorEye[1];
		psycho.curPosition[psycho.curSample][2] = player.vectorEye[2];
		psycho.curDirection[psycho.curSample][0] = player.vectorLook[0];
		psycho.curDirection[psycho.curSample][1] = player.vectorLook[1];
		psycho.curDirection[psycho.curSample][2] = player.vectorLook[2];
		psycho.curAzimuth[psycho.curSample] = frustum.azimuth;
		psycho.curElevation[psycho.curSample] = frustum.elevation;
		psycho.curSample++;
		}


	//Abort Trial Functions
	if (psycho.on == 1 & psycho.started == 1)
		{
		//Trial to Long
		if (psycho.curSample > 100000 | psycho.stop == 1)
			{
			psycho.stop = 0;
			psycho.on == 1;
			psycho.started = 0;
			gravitation.collision = 0;
			SavePsychophysics();
			InitializePsychophysics();
			InitializePosition();
			}
		
		//Out of bounds
		if (player.vectorEye[0] < -3.75 | player.vectorEye[0] > 3.75)
			{
			psycho.on == 1;
			psycho.started = 0;
			gravitation.collision = 0;
			SavePsychophysics();
			InitializePsychophysics();
			InitializePosition();
			}
		
		//Out of bounds
		if (player.vectorEye[2] < -3.75 | player.vectorEye[2] > 3.75)
			{
			psycho.on == 1;
			psycho.started = 0;
			gravitation.collision = 0;
			SavePsychophysics();
			InitializePsychophysics();
			InitializePosition();
			}
			
		//At Center
		if (player.vectorEye[0] < 0.05 & player.vectorEye[0] > -0.05 & player.vectorEye[2] < 0.05 & player.vectorEye[2] > -0.05)
			{
			psycho.on == 1;
			psycho.started = 0;
			gravitation.collision = 0;
			SavePsychophysics();
			InitializePsychophysics();
			InitializePosition();
			}
		
		}
		

	//Prevent heavy gravity
	if (timing.elapsed > 100)
		{timing.elapsed = 0;}


	//Update Jump Trajectory
	if (moving.jumping == 1)
		{
		moving.jumpspeed = moving.jumpspeed - moving.jumpspeed*moving.jumpspeed_decay;
		player.vectorEye[1] = player.vectorEye[1] + moving.jumpspeed;
		player.vectorLook[1] = player.vectorLook[1] + moving.jumpspeed;
		}
		


	//Move if needed
	if (moving.forward == 1)
		{MoveForward(timing.elapsed);}
	if (moving.backward == 1)
		{MoveBackward(timing.elapsed);}
	if (moving.strafingleft == 1)
		{StrafeLeft(timing.elapsed);}
	if (moving.strafingright == 1)
		{StrafeRight(timing.elapsed);}
	if (moving.rotateright == 1)
		{RotateRight(timing.elapsed);}
	if (moving.rotateleft == 1)
		{RotateLeft(timing.elapsed);}
	if (moving.rotateup == 1)
		{RotateUp(timing.elapsed);}
	if (moving.rotatedown == 1)
		{RotateDown(timing.elapsed);}

	//Gravity
	if (gravitation.on == 1)
		{
		Gravity(timing.elapsed);
		}
	NearestNeigbor();
	
	
	//Reset Time
	returntimer();
	timing.base1 = timing.curtime;
	timing.elapsed = timing.now1;


	//Head Bobbing
	if (moving.forward == 1 | moving.backward == 1 | moving.strafingleft == 1 | moving.strafingright == 1)
		{
		moving.headbobbing = moving.headbobbing + timing.elapsed;
		moving.hbf = sin(moving.headbobbing/75)/1600;
		}
	if (moving.jumping == 1)
		{
		moving.headbobbing = 0;
		moving.hbf = 0;
		}

	
	//Update view
	glLoadIdentity();
	glMatrixMode( GL_MODELVIEW );
	gluLookAt(player.vectorEye[0],player.vectorEye[1]+moving.hbf,player.vectorEye[2],player.vectorLook[0],player.vectorLook[1],player.vectorLook[2],player.vectorUp[0],player.vectorUp[1],player.vectorUp[2]);
	CalculateFrustrum();
	glLightfv(GL_LIGHT1,GL_POSITION,sun.position);
	glLightfv(GL_LIGHT2,GL_POSITION,ambiance.position);

}
//-------------------------------------------------------------------------------------------------------
int main ( int argc, char** argv )
{
	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(160, 120 );
  	glutInitWindowSize(350, 500 );
	glutCreateWindow("Template");
	curTrial = 0;
	CreateInitialLocations();
	InitializeParameters();
	LoadWorld();
	LoadTextures();
	InitializeFaces();
	Init();
	returntimer();
	glutKeyboardFunc(key);	
    glutKeyboardUpFunc(keyUp);
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutIdleFunc(glutIdle);
	glutPositionWindow(1700,100);
	glutSetCursor(GLUT_CURSOR_NONE);
	glutFullScreen();
	glutMainLoop();
	return 0;
}
//-------------------------------------------------------------------------------------------------------

  

