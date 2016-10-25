#include <math.h>           /* C header for any math functions               */
#include <stdio.h>          /* C header for standard I/O                     */
#include <string.h>         /* For String compare                            */
#include <stdlib.h>
#include <GLUT/glut.h>	  
#include <mach-o/dyld.h>
#include <limits.h>
#include <libgen.h>


//File Handles
FILE *stream;
char pathbuf[PATH_MAX + 1];
char *dirName;
char loadName[200];


//Globals
int buf[1];
int xlook,ylook,zlook;
int count;
int i,j,l,m;
int nx,ny,nz;
int xi,yi,zi;
int nfaces_reduced;
int nfaces;
int curTrial;
float xv,yv,zv;
float val;
float dist,z;
float framerate;
float fbuf[0];
float length;
float x,y,z,dist;
float angle;


//World
struct worldstruct {
	float boxsize;
	float boxradius;
	int grid[513][513][65];
	int faces[513][513][65][6];
	int viewdepth;
	};
	


//Texture + Materials Structure
struct texturestructure {
	unsigned int IDs[20];
	float coords[256][4];
	float X1[6];
	float X2[6];
	float Y1[6];
	float Y2[6];
	float materials[128][3];
	float mat[4];
	float amb[4];
	float dif[4];
	float ems[4];
	};
	

//Terrain Drawing
struct drawingstruct {
	int trees;
	int clouds;
	int landmarks;
	int nClouds;
	int textures;
	int texturemode;
	};
	

//Clouds Textures
struct cloudstructure {
	float position[100][3];
	float size[100][3];
	};

	
//Gravity Structure
struct gravitystruct {
	float decay;
	float initial;
	int on;
	int collision;
	};

	

//Time Structure
struct timestruct {
	unsigned long curtime;
	unsigned long base1;
	unsigned long base2;
	unsigned long now1;
	unsigned long now2;
	float elapsed;
	};



//Frustum Structure
struct frustrumstruct {
	float planes[6][7];
	float ntl[3];
	float ntr[3];
	float nbl[3];
	float nbr[3];
	float ftl[3];
	float ftr[3];
	float fbl[3];
	float fbr[3];
	float nc[3];
	float fc[3];
	float nh;
	float nw;
	float fh;
	float fw;
	float fov;
	float nearDist;
	float farDist;
	float aspect;
	float elevation;
	float azimuth;
	int collision;
	int within;
	};



//Agent Structure
struct agent {
	float vectorLook[3];
	float vectorEye[3];
	float vectorUp[3];
	float vectorNormal[3];
	float vectorRight[3];
	float vectorGlobal[3];
	float vector[3];
	float length;
	};
	
	
//Moving Structure
struct movingstructure {
	float rotationspeed;
	float bubble;
	float hbf;
	float headbobbing;
	float waiting;
	float backward;
	float forward;
	float strafingright;
	float strafingleft;
	float rotateright;
	float rotateleft;
	float rotateup;
	float rotatedown;
	float jumping;
	float collision;
	float mouse_sentitivity;
	float stepsize;	
	float jumpspeed_initial;
	float jumpspeed_decay;
	float jumpspeed;
	};


//Light Structure
struct light {
	int on;
	GLfloat position[4];
	GLfloat ambient[4];
	GLfloat specular[4];
	GLfloat diffuse[4];
	GLfloat attenuation_constant;
	GLfloat attenuation_linear;
	GLfloat attenuation_quadratic;
	};



//Selected Block Structure
struct selectstructure {
	int xi;
	int yi;
	int zi;
	int on;
	};
	

//Information Structure
struct information {
	char position_string[100];
	char direction_string[100];
	char framerate_string[100];
	char selected_string[100];
	char faces_string[100];
	char block_string[100];
	char information_string[100];
	char continue_string[100];
	char azimuthelevationstring[100];
	char savename[100];
	int executable;
	int display;
	int currentframe;
	};
	
	
	
//Atmospherics Structure
struct atmospherics {
	int fogon;
	GLfloat fogcolor[3];
	GLfloat skycolor[3];
	GLfloat fogstart;
	GLfloat fogdensity;
	};
	

//Psychophysics Structure
struct psychstructure {
	int on;
	int stop;
	int started;
	int curSample;
	float startPosition[3];
	float startAzimuth;
	float startElevation;
	float curPosition[1000000][3];
	float curDirection[1000000][3];
	float curAzimuth[1000000];
	float curElevation[1000000];
	float startLocations[25][3];
	};



//Define Structure Variables
struct light sun;
struct light ambiance;
struct agent player;
struct information info;
struct atmospherics atmosphere;
struct timestruct timing;
struct frustrumstruct frustum;
struct movingstructure moving;
struct gravitystruct gravitation;
struct drawingstruct drawing;
struct texturestructure tex;
struct worldstruct world;
struct cloudstructure clouds;
struct selectstructure selected;
struct psychstructure psycho;
