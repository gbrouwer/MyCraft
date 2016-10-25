#include <math.h>           /* C header for any math functions               */
#include <stdio.h>          /* C header for standard I/O                     */
#include <string.h>         /* For String compare                            */
#include <stdlib.h>
#include <GLUT/glut.h>	  
#include <parameters.h>


//-------------------------------------------------------------------------------------------------------
void DefineLights()
{

	//Sun
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,sun.diffuse);
	glLightfv(GL_LIGHT1,GL_AMBIENT,sun.ambient);
	glLightfv(GL_LIGHT1,GL_POSITION,sun.position);
	glLightfv(GL_LIGHT1,GL_SPECULAR,sun.specular);
	glLightf(GL_LIGHT1,GL_CONSTANT_ATTENUATION,sun.attenuation_constant);
	glLightf(GL_LIGHT1,GL_LINEAR_ATTENUATION,sun.attenuation_linear);
	glLightf(GL_LIGHT1,GL_QUADRATIC_ATTENUATION,sun.attenuation_quadratic); 
	if (sun.on == 1)
		{glEnable(GL_LIGHT1);}
	else
		{glDisable(GL_LIGHT1);}

	//Ambiance
	glLightfv(GL_LIGHT2,GL_DIFFUSE,ambiance.diffuse);
	glLightfv(GL_LIGHT2,GL_AMBIENT,ambiance.ambient);
	glLightfv(GL_LIGHT2,GL_POSITION,ambiance.position);
	glLightfv(GL_LIGHT2,GL_SPECULAR,ambiance.specular);
	glLightf(GL_LIGHT2,GL_CONSTANT_ATTENUATION,ambiance.attenuation_constant);
	glLightf(GL_LIGHT2,GL_LINEAR_ATTENUATION,ambiance.attenuation_linear);
	glLightf(GL_LIGHT2,GL_QUADRATIC_ATTENUATION,ambiance.attenuation_quadratic); 
	if (ambiance.on == 1)
		{glEnable(GL_LIGHT2);}
	else
		{glDisable(GL_LIGHT2);}
		

}
//-------------------------------------------------------------------------------------------------------
void DefineAtmospherics()
{

	//Fog
	if (atmosphere.fogon == 1)
		{
		glEnable(GL_FOG);
		glFogfv(GL_FOG_COLOR,atmosphere.fogcolor);
		glFogf(GL_FOG_START,atmosphere.fogstart);
		glFogf(GL_FOG_MODE,GL_EXP2);
		glFogf(GL_FOG_DENSITY,atmosphere.fogdensity);
		}
	else 
		{
		glDisable(GL_FOG);
		}

}
//-------------------------------------------------------------------------------------------------------
