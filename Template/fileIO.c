#include <math.h>           /* C header for any math functions               */
#include <stdio.h>          /* C header for standard I/O                     */
#include <string.h>         /* For String compare                            */
#include <stdlib.h>
#include <unistd.h>
#include <mach-o/dyld.h>
#include <GLUT/glut.h>	  
#include <parameters.h>
#include <limits.h>
#include <libgen.h>


//-------------------------------------------------------------------------------------------------------
void GetPath(char *relativepath)
{

 	//Get Path
	int  bufsize = sizeof(pathbuf);
	_NSGetExecutablePath(pathbuf, &bufsize);
	dirName = dirname(pathbuf);
	if (info.executable == 1)
		{sprintf(loadName,"%s/%s",dirName,relativepath);}
	else
		{sprintf(loadName,"%s",relativepath);}

}
//-------------------------------------------------------------------------------------------------------
void LoadWorld(void)
{

	//Get Path
	GetPath("/Users/gijs/Genesis/mycraft/data/models/azure_world.dat");
	fprintf(stderr,"Selected Path: %s\n",loadName);
	
	//Read Grid
	stream = fopen(loadName,"r");
	for (l=0;l<65;l++)
		{
		for (i=0;i<513;i++)
			{
			for (j=0;j<513;j++)
				{
				fread(buf,1,2,stream);
				world.grid[i][j][l] = buf[0];
				}
			}
		}
	fclose(stream);
	fprintf(stderr,"Succesfully loaded world\n");

}
//-------------------------------------------------------------------------------------------------------
void CreateClouds(void)
{
	
	//Create Random Clouds
	int c1 = 0;
	float v1,v2,v3;
	for (i=0;i<drawing.nClouds;i++)
		{
		for (j=0;j<drawing.nClouds;j++)
			{
			//Position
			x = (float) i / drawing.nClouds * 513;
			y = (float) j / drawing.nClouds * 513;
			z = rand() % 10;
			v1 = rand() % 100;
			v2 = rand() % 100;
			v1 = (v1 - 50)/50;
			v2 = (v2 - 50)/50;
			x = (x - 256)/64;
			y = (y - 256)/64;
			x = x + v1;
			y = y + v2;
			z = 1 - (z/50);
			clouds.position[c1][0] = x;
			clouds.position[c1][1] = y;
			clouds.position[c1][2] = z;

			//Size
			v1 = rand() % 100;
			v2 = rand() % 100;
			v3 = rand() % 100;
			v1 = 0.05 + v1/200;
			v2 = 0.05 + v2/200;
			if (v1 < 0.01 | v1 < 0.01)
				{
				v1 = 0;
				v2 = 0;
				}
			v3 = v3 / 1500;
			clouds.size[c1][0] = v1;
			clouds.size[c1][1] = v2;
			clouds.size[c1][2] = v3;
			c1++;
			}
		}


}
//-------------------------------------------------------------------------------------------------------
void CreateInitialLocations(void)
{
	float val;
	float values[1000];
	int nGridPoints = 5;
	int count = 0;
	int i1,i2;
	float e1,e2,e3;
	float f1,f2,f3;
	
	//Grid Locations
	for (i=1;i<nGridPoints+1;i++)
		{
		val = i;
		val = val / (nGridPoints+2-1);	
		val = val * 8;
		val = val - 4;
		values[i-1] = val;
		}

	//Store Locations
	for (i=0;i<nGridPoints;i++)
		{
		for (j=0;j<nGridPoints;j++)
			{
			if (i == 2 & j == 2)
				{
				}
			else
				{
				psycho.startLocations[count][0] = values[i];
				psycho.startLocations[count][1] = 1;
				psycho.startLocations[count][2] = values[j];
				count++;
				}
			}
		}
	
	//Randomize Locations
	for (i=0;i<1000;i++)
		{
		i1 = rand()%count;
		i2 = rand()%count;
		e1 = psycho.startLocations[i1][0];
		e2 = psycho.startLocations[i1][1];
		e3 = psycho.startLocations[i1][2];
		f1 = psycho.startLocations[i2][0];
		f2 = psycho.startLocations[i2][1];
		f3 = psycho.startLocations[i2][2];
		psycho.startLocations[i1][0] = f1;
		psycho.startLocations[i1][1] = f2;
		psycho.startLocations[i1][2] = f3;
		psycho.startLocations[i2][0] = e1;
		psycho.startLocations[i2][1] = e2;
		psycho.startLocations[i2][2] = e3;
		}
	
}
//-------------------------------------------------------------------------------------------------------
void WriteWorld(void)
{
	
	GetPath("models/azure_world_save.dat");
	fprintf(stderr,"Selected Path: %s\n",loadName);
	stream = fopen(loadName,"w");
	for (l=0;l<65;l++)
		{
		for (i=0;i<513;i++)
			{
			for (j=0;j<513;j++)
				{
				buf[0] = world.grid[i][j][l];
				fwrite(buf,1,2,stream);
				}
			}
		}
	fclose(stream);
}
//-------------------------------------------------------------------------------------------------------
void SavePsychophysics(void)
{
	int ibuf[1];
	float fbuf[1];
	char *trialname;

 	//Get Path
	sprintf(trialname,"save/azure_trial%d.dat",curTrial);
	GetPath(trialname);
	fprintf(stderr,"Selected Path: %s\n",loadName);
	stream = fopen(loadName,"w");
	ibuf[0] = psycho.curSample;
	fwrite(ibuf,1,4,stream);
	fbuf[0] = psycho.startPosition[0];
	fwrite(fbuf,1,4,stream);
	fbuf[0] = psycho.startPosition[1];
	fwrite(fbuf,1,4,stream);
	fbuf[0] = psycho.startPosition[2];
	fwrite(fbuf,1,4,stream);
	fbuf[0] = psycho.startElevation;
	fwrite(fbuf,1,4,stream);
	fbuf[0] = psycho.startAzimuth;
	fwrite(fbuf,1,4,stream);

	for (i=0;i<psycho.curSample;i++)
		{
		fbuf[0] = psycho.curPosition[i][0];
		fwrite(fbuf,1,4,stream);
		fbuf[0] = psycho.curPosition[i][1];
		fwrite(fbuf,1,4,stream);
		fbuf[0] = psycho.curPosition[i][2];
		fwrite(fbuf,1,4,stream);
		}
	for (i=0;i<psycho.curSample;i++)
		{
		fbuf[0] = psycho.curDirection[i][0];
		fwrite(fbuf,1,4,stream);
		fbuf[0] = psycho.curDirection[i][1];
		fwrite(fbuf,1,4,stream);
		fbuf[0] = psycho.curDirection[i][2];
		fwrite(fbuf,1,4,stream);
		}
		
	for (i=0;i<psycho.curSample;i++)
		{
		fbuf[0] = psycho.curAzimuth[i];
		fwrite(fbuf,1,4,stream);
		}
	for (i=0;i<psycho.curSample;i++)
		{
		fbuf[0] = psycho.curElevation[i];
		fwrite(fbuf,1,4,stream);
		}
	fclose(stream);




}
//-------------------------------------------------------------------------------------------------------
void ScreenDump(void)
{
	char savename[100];
	GLubyte data[1680*1050*3];

	sprintf(savename,"/Users/gijs/Genesis/mycraft/data/screens/screen%d.dat",info.currentframe);
	GetPath(savename);
	fprintf(stderr,"Selected Path: %s\n",loadName);

	//Get Pixels
	glReadPixels(0, 0, 1680,1050,GL_RGB,GL_UNSIGNED_BYTE, data);
	stream = fopen(loadName,"w");
	fwrite(data,1680*1050*3,1,stream);
	fclose(stream);
	info.currentframe++;
	
}
//-------------------------------------------------------------------------------------------------------
