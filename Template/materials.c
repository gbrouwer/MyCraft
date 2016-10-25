#include <math.h>           /* C header for any math functions               */
#include <stdio.h>          /* C header for standard I/O                     */
#include <string.h>         /* For String compare                            */
#include <stdlib.h>
#include <GLUT/glut.h>	  
#include <parameters.h>

//-------------------------------------------------------------------------------------------------------
void setTextureAndMaterial(int texture)
{

	//Get Material Colors
	tex.mat[0] = 1.0;
	tex.mat[1] = 1.0;
	tex.mat[2] = 1.0;
	tex.mat[3] = 1.0;
	tex.ems[0] = 0.5;
	tex.ems[1] = 0.5;
	tex.ems[2] = 0.5;
	tex.ems[3] = 0.0;
	
	
	//Basalt Texture
	if (texture == 1)
		{
		tex.X1[0] = tex.coords[0][0];tex.X2[0] = tex.coords[0][1];tex.Y1[0] = tex.coords[0][2];tex.Y2[0] = tex.coords[0][3];
		tex.X1[1] = tex.coords[0][0];tex.X2[1] = tex.coords[0][1];tex.Y1[1] = tex.coords[0][2];tex.Y2[1] = tex.coords[0][3];
		tex.X1[2] = tex.coords[0][0];tex.X2[2] = tex.coords[0][1];tex.Y1[2] = tex.coords[0][2];tex.Y2[2] = tex.coords[0][3];
		tex.X1[3] = tex.coords[0][0];tex.X2[3] = tex.coords[0][1];tex.Y1[3] = tex.coords[0][2];tex.Y2[3] = tex.coords[0][3];
		tex.X1[4] = tex.coords[0][0];tex.X2[4] = tex.coords[0][1];tex.Y1[4] = tex.coords[0][2];tex.Y2[4] = tex.coords[0][3];
		tex.X1[5] = tex.coords[0][0];tex.X2[5] = tex.coords[0][1];tex.Y1[5] = tex.coords[0][2];tex.Y2[5] = tex.coords[0][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}				


	//Sand Texture
	if (texture == 2)
		{
		tex.X1[0] = tex.coords[1][0];tex.X2[0] = tex.coords[1][1];tex.Y1[0] = tex.coords[1][2];tex.Y2[0] = tex.coords[1][3];
		tex.X1[1] = tex.coords[1][0];tex.X2[1] = tex.coords[1][1];tex.Y1[1] = tex.coords[1][2];tex.Y2[1] = tex.coords[1][3];
		tex.X1[2] = tex.coords[1][0];tex.X2[2] = tex.coords[1][1];tex.Y1[2] = tex.coords[1][2];tex.Y2[2] = tex.coords[1][3];
		tex.X1[3] = tex.coords[1][0];tex.X2[3] = tex.coords[1][1];tex.Y1[3] = tex.coords[1][2];tex.Y2[3] = tex.coords[1][3];
		tex.X1[4] = tex.coords[1][0];tex.X2[4] = tex.coords[1][1];tex.Y1[4] = tex.coords[1][2];tex.Y2[4] = tex.coords[1][3];
		tex.X1[5] = tex.coords[1][0];tex.X2[5] = tex.coords[1][1];tex.Y1[5] = tex.coords[1][2];tex.Y2[5] = tex.coords[1][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}	


	//Water Texture
	if (texture == 3)
		{
		tex.X1[0] = tex.coords[2][0];tex.X2[0] = tex.coords[2][1];tex.Y1[0] = tex.coords[2][2];tex.Y2[0] = tex.coords[2][3];
		tex.X1[1] = tex.coords[2][0];tex.X2[1] = tex.coords[2][1];tex.Y1[1] = tex.coords[2][2];tex.Y2[1] = tex.coords[2][3];
		tex.X1[2] = tex.coords[2][0];tex.X2[2] = tex.coords[2][1];tex.Y1[2] = tex.coords[2][2];tex.Y2[2] = tex.coords[2][3];
		tex.X1[3] = tex.coords[2][0];tex.X2[3] = tex.coords[2][1];tex.Y1[3] = tex.coords[2][2];tex.Y2[3] = tex.coords[2][3];
		tex.X1[4] = tex.coords[2][0];tex.X2[4] = tex.coords[2][1];tex.Y1[4] = tex.coords[2][2];tex.Y2[4] = tex.coords[2][3];
		tex.X1[5] = tex.coords[2][0];tex.X2[5] = tex.coords[2][1];tex.Y1[5] = tex.coords[2][2];tex.Y2[5] = tex.coords[2][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}	


	//Grassland Texture
	if (texture == 4)
		{
		tex.X1[0] = tex.coords[19][0];tex.X2[0] = tex.coords[19][1];tex.Y1[0] = tex.coords[19][2];tex.Y2[0] = tex.coords[19][3];
		tex.X1[1] = tex.coords[19][0];tex.X2[1] = tex.coords[19][1];tex.Y1[1] = tex.coords[19][2];tex.Y2[1] = tex.coords[19][3];
		tex.X1[2] = tex.coords[3][0];tex.X2[2] = tex.coords[3][1];tex.Y1[2] = tex.coords[3][2];tex.Y2[2] = tex.coords[3][3];
		tex.X1[3] = tex.coords[3][0];tex.X2[3] = tex.coords[3][1];tex.Y1[3] = tex.coords[3][2];tex.Y2[3] = tex.coords[3][3];
		tex.X1[4] = tex.coords[19][0];tex.X2[4] = tex.coords[19][1];tex.Y1[4] = tex.coords[19][2];tex.Y2[4] = tex.coords[19][3];
		tex.X1[5] = tex.coords[19][0];tex.X2[5] = tex.coords[19][1];tex.Y1[5] = tex.coords[19][2];tex.Y2[5] = tex.coords[19][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}	
	//Grassland Texture
	if (texture == 5)
		{
		tex.X1[0] = tex.coords[20][0];tex.X2[0] = tex.coords[20][1];tex.Y1[0] = tex.coords[20][2];tex.Y2[0] = tex.coords[20][3];
		tex.X1[1] = tex.coords[20][0];tex.X2[1] = tex.coords[20][1];tex.Y1[1] = tex.coords[20][2];tex.Y2[1] = tex.coords[20][3];
		tex.X1[2] = tex.coords[4][0];tex.X2[2] = tex.coords[4][1];tex.Y1[2] = tex.coords[4][2];tex.Y2[2] = tex.coords[4][3];
		tex.X1[3] = tex.coords[4][0];tex.X2[3] = tex.coords[4][1];tex.Y1[3] = tex.coords[4][2];tex.Y2[3] = tex.coords[4][3];
		tex.X1[4] = tex.coords[20][0];tex.X2[4] = tex.coords[20][1];tex.Y1[4] = tex.coords[20][2];tex.Y2[4] = tex.coords[20][3];
		tex.X1[5] = tex.coords[20][0];tex.X2[5] = tex.coords[20][1];tex.Y1[5] = tex.coords[20][2];tex.Y2[5] = tex.coords[20][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}	
	//Grassland Texture
	if (texture == 6)
		{
		tex.X1[0] = tex.coords[21][0];tex.X2[0] = tex.coords[21][1];tex.Y1[0] = tex.coords[21][2];tex.Y2[0] = tex.coords[21][3];
		tex.X1[1] = tex.coords[21][0];tex.X2[1] = tex.coords[21][1];tex.Y1[1] = tex.coords[21][2];tex.Y2[1] = tex.coords[21][3];
		tex.X1[2] = tex.coords[5][0];tex.X2[2] = tex.coords[5][1];tex.Y1[2] = tex.coords[5][2];tex.Y2[2] = tex.coords[5][3];
		tex.X1[3] = tex.coords[5][0];tex.X2[3] = tex.coords[5][1];tex.Y1[3] = tex.coords[5][2];tex.Y2[3] = tex.coords[5][3];
		tex.X1[4] = tex.coords[21][0];tex.X2[4] = tex.coords[21][1];tex.Y1[4] = tex.coords[21][2];tex.Y2[4] = tex.coords[21][3];
		tex.X1[5] = tex.coords[21][0];tex.X2[5] = tex.coords[21][1];tex.Y1[5] = tex.coords[21][2];tex.Y2[5] = tex.coords[21][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}	
	//Grassland Texture
	if (texture == 7)
		{
		tex.X1[0] = tex.coords[22][0];tex.X2[0] = tex.coords[22][1];tex.Y1[0] = tex.coords[22][2];tex.Y2[0] = tex.coords[22][3];
		tex.X1[1] = tex.coords[22][0];tex.X2[1] = tex.coords[22][1];tex.Y1[1] = tex.coords[22][2];tex.Y2[1] = tex.coords[22][3];
		tex.X1[2] = tex.coords[6][0];tex.X2[2] = tex.coords[6][1];tex.Y1[2] = tex.coords[6][2];tex.Y2[2] = tex.coords[6][3];
		tex.X1[3] = tex.coords[6][0];tex.X2[3] = tex.coords[6][1];tex.Y1[3] = tex.coords[6][2];tex.Y2[3] = tex.coords[6][3];
		tex.X1[4] = tex.coords[22][0];tex.X2[4] = tex.coords[22][1];tex.Y1[4] = tex.coords[22][2];tex.Y2[4] = tex.coords[22][3];
		tex.X1[5] = tex.coords[22][0];tex.X2[5] = tex.coords[22][1];tex.Y1[5] = tex.coords[22][2];tex.Y2[5] = tex.coords[22][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}	
	//Grassland Texture
	if (texture == 8)
		{
		tex.X1[0] = tex.coords[23][0];tex.X2[0] = tex.coords[23][1];tex.Y1[0] = tex.coords[23][2];tex.Y2[0] = tex.coords[23][3];
		tex.X1[1] = tex.coords[23][0];tex.X2[1] = tex.coords[23][1];tex.Y1[1] = tex.coords[23][2];tex.Y2[1] = tex.coords[23][3];
		tex.X1[2] = tex.coords[7][0];tex.X2[2] = tex.coords[7][1];tex.Y1[2] = tex.coords[7][2];tex.Y2[2] = tex.coords[7][3];
		tex.X1[3] = tex.coords[7][0];tex.X2[3] = tex.coords[7][1];tex.Y1[3] = tex.coords[7][2];tex.Y2[3] = tex.coords[7][3];
		tex.X1[4] = tex.coords[23][0];tex.X2[4] = tex.coords[23][1];tex.Y1[4] = tex.coords[23][2];tex.Y2[4] = tex.coords[23][3];
		tex.X1[5] = tex.coords[23][0];tex.X2[5] = tex.coords[23][1];tex.Y1[5] = tex.coords[23][2];tex.Y2[5] = tex.coords[23][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}	


	//Stone Texture
	if (texture == 9)
		{
		tex.X1[0] = tex.coords[8][0];tex.X2[0] = tex.coords[8][1];tex.Y1[0] = tex.coords[8][2];tex.Y2[0] = tex.coords[8][3];
		tex.X1[1] = tex.coords[8][0];tex.X2[1] = tex.coords[8][1];tex.Y1[1] = tex.coords[8][2];tex.Y2[1] = tex.coords[8][3];
		tex.X1[2] = tex.coords[8][0];tex.X2[2] = tex.coords[8][1];tex.Y1[2] = tex.coords[8][2];tex.Y2[2] = tex.coords[8][3];
		tex.X1[3] = tex.coords[8][0];tex.X2[3] = tex.coords[8][1];tex.Y1[3] = tex.coords[8][2];tex.Y2[3] = tex.coords[8][3];
		tex.X1[4] = tex.coords[8][0];tex.X2[4] = tex.coords[8][1];tex.Y1[4] = tex.coords[8][2];tex.Y2[4] = tex.coords[8][3];
		tex.X1[5] = tex.coords[8][0];tex.X2[5] = tex.coords[8][1];tex.Y1[5] = tex.coords[8][2];tex.Y2[5] = tex.coords[8][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}	
	//Stone Texture
	if (texture == 10)
		{
		tex.X1[0] = tex.coords[9][0];tex.X2[0] = tex.coords[9][1];tex.Y1[0] = tex.coords[9][2];tex.Y2[0] = tex.coords[9][3];
		tex.X1[1] = tex.coords[9][0];tex.X2[1] = tex.coords[9][1];tex.Y1[1] = tex.coords[9][2];tex.Y2[1] = tex.coords[9][3];
		tex.X1[2] = tex.coords[9][0];tex.X2[2] = tex.coords[9][1];tex.Y1[2] = tex.coords[9][2];tex.Y2[2] = tex.coords[9][3];
		tex.X1[3] = tex.coords[9][0];tex.X2[3] = tex.coords[9][1];tex.Y1[3] = tex.coords[9][2];tex.Y2[3] = tex.coords[9][3];
		tex.X1[4] = tex.coords[9][0];tex.X2[4] = tex.coords[9][1];tex.Y1[4] = tex.coords[9][2];tex.Y2[4] = tex.coords[9][3];
		tex.X1[5] = tex.coords[9][0];tex.X2[5] = tex.coords[9][1];tex.Y1[5] = tex.coords[9][2];tex.Y2[5] = tex.coords[9][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}	
	//Stone Texture
	if (texture == 11)
		{
		tex.X1[0] = tex.coords[10][0];tex.X2[0] = tex.coords[10][1];tex.Y1[0] = tex.coords[10][2];tex.Y2[0] = tex.coords[10][3];
		tex.X1[1] = tex.coords[10][0];tex.X2[1] = tex.coords[10][1];tex.Y1[1] = tex.coords[10][2];tex.Y2[1] = tex.coords[10][3];
		tex.X1[2] = tex.coords[10][0];tex.X2[2] = tex.coords[10][1];tex.Y1[2] = tex.coords[10][2];tex.Y2[2] = tex.coords[10][3];
		tex.X1[3] = tex.coords[10][0];tex.X2[3] = tex.coords[10][1];tex.Y1[3] = tex.coords[10][2];tex.Y2[3] = tex.coords[10][3];
		tex.X1[4] = tex.coords[10][0];tex.X2[4] = tex.coords[10][1];tex.Y1[4] = tex.coords[10][2];tex.Y2[4] = tex.coords[10][3];
		tex.X1[5] = tex.coords[10][0];tex.X2[5] = tex.coords[10][1];tex.Y1[5] = tex.coords[10][2];tex.Y2[5] = tex.coords[10][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}	
	//Stone Texture
	if (texture == 12)
		{
		tex.X1[0] = tex.coords[11][0];tex.X2[0] = tex.coords[11][1];tex.Y1[0] = tex.coords[11][2];tex.Y2[0] = tex.coords[11][3];
		tex.X1[1] = tex.coords[11][0];tex.X2[1] = tex.coords[11][1];tex.Y1[1] = tex.coords[11][2];tex.Y2[1] = tex.coords[11][3];
		tex.X1[2] = tex.coords[11][0];tex.X2[2] = tex.coords[11][1];tex.Y1[2] = tex.coords[11][2];tex.Y2[2] = tex.coords[11][3];
		tex.X1[3] = tex.coords[11][0];tex.X2[3] = tex.coords[11][1];tex.Y1[3] = tex.coords[11][2];tex.Y2[3] = tex.coords[11][3];
		tex.X1[4] = tex.coords[11][0];tex.X2[4] = tex.coords[11][1];tex.Y1[4] = tex.coords[11][2];tex.Y2[4] = tex.coords[11][3];
		tex.X1[5] = tex.coords[11][0];tex.X2[5] = tex.coords[11][1];tex.Y1[5] = tex.coords[11][2];tex.Y2[5] = tex.coords[11][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}	
	//Stone Texture
	if (texture == 13)
		{
		tex.X1[0] = tex.coords[12][0];tex.X2[0] = tex.coords[12][1];tex.Y1[0] = tex.coords[12][2];tex.Y2[0] = tex.coords[12][3];
		tex.X1[1] = tex.coords[12][0];tex.X2[1] = tex.coords[12][1];tex.Y1[1] = tex.coords[12][2];tex.Y2[1] = tex.coords[12][3];
		tex.X1[2] = tex.coords[12][0];tex.X2[2] = tex.coords[12][1];tex.Y1[2] = tex.coords[12][2];tex.Y2[2] = tex.coords[12][3];
		tex.X1[3] = tex.coords[12][0];tex.X2[3] = tex.coords[12][1];tex.Y1[3] = tex.coords[12][2];tex.Y2[3] = tex.coords[12][3];
		tex.X1[4] = tex.coords[12][0];tex.X2[4] = tex.coords[12][1];tex.Y1[4] = tex.coords[12][2];tex.Y2[4] = tex.coords[12][3];
		tex.X1[5] = tex.coords[12][0];tex.X2[5] = tex.coords[12][1];tex.Y1[5] = tex.coords[12][2];tex.Y2[5] = tex.coords[12][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}				
		
							
	//Tree
	if (texture == 32)
		{
		tex.X1[0] = tex.coords[32][0];tex.X2[0] = tex.coords[32][1];tex.Y1[0] = tex.coords[32][2];tex.Y2[0] = tex.coords[32][3];
		tex.X1[1] = tex.coords[32][0];tex.X2[1] = tex.coords[32][1];tex.Y1[1] = tex.coords[32][2];tex.Y2[1] = tex.coords[32][3];
		tex.X1[2] = tex.coords[32][0];tex.X2[2] = tex.coords[32][1];tex.Y1[2] = tex.coords[32][2];tex.Y2[2] = tex.coords[32][3];
		tex.X1[3] = tex.coords[32][0];tex.X2[3] = tex.coords[32][1];tex.Y1[3] = tex.coords[32][2];tex.Y2[3] = tex.coords[32][3];
		tex.X1[4] = tex.coords[32][0];tex.X2[4] = tex.coords[32][1];tex.Y1[4] = tex.coords[32][2];tex.Y2[4] = tex.coords[32][3];
		tex.X1[5] = tex.coords[32][0];tex.X2[5] = tex.coords[32][1];tex.Y1[5] = tex.coords[32][2];tex.Y2[5] = tex.coords[32][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}																			
	//Tree
	if (texture == 33)
		{
		tex.X1[0] = tex.coords[33][0];tex.X2[0] = tex.coords[33][1];tex.Y1[0] = tex.coords[33][2];tex.Y2[0] = tex.coords[33][3];
		tex.X1[1] = tex.coords[33][0];tex.X2[1] = tex.coords[33][1];tex.Y1[1] = tex.coords[33][2];tex.Y2[1] = tex.coords[33][3];
		tex.X1[2] = tex.coords[33][0];tex.X2[2] = tex.coords[33][1];tex.Y1[2] = tex.coords[33][2];tex.Y2[2] = tex.coords[33][3];
		tex.X1[3] = tex.coords[33][0];tex.X2[3] = tex.coords[33][1];tex.Y1[3] = tex.coords[33][2];tex.Y2[3] = tex.coords[33][3];
		tex.X1[4] = tex.coords[33][0];tex.X2[4] = tex.coords[33][1];tex.Y1[4] = tex.coords[33][2];tex.Y2[4] = tex.coords[33][3];
		tex.X1[5] = tex.coords[33][0];tex.X2[5] = tex.coords[33][1];tex.Y1[5] = tex.coords[33][2];tex.Y2[5] = tex.coords[33][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}
	//Tree
	if (texture == 34)
		{
		tex.X1[0] = tex.coords[34][0];tex.X2[0] = tex.coords[34][1];tex.Y1[0] = tex.coords[34][2];tex.Y2[0] = tex.coords[34][3];
		tex.X1[1] = tex.coords[34][0];tex.X2[1] = tex.coords[34][1];tex.Y1[1] = tex.coords[34][2];tex.Y2[1] = tex.coords[34][3];
		tex.X1[2] = tex.coords[34][0];tex.X2[2] = tex.coords[34][1];tex.Y1[2] = tex.coords[34][2];tex.Y2[2] = tex.coords[34][3];
		tex.X1[3] = tex.coords[34][0];tex.X2[3] = tex.coords[34][1];tex.Y1[3] = tex.coords[34][2];tex.Y2[3] = tex.coords[34][3];
		tex.X1[4] = tex.coords[34][0];tex.X2[4] = tex.coords[34][1];tex.Y1[4] = tex.coords[34][2];tex.Y2[4] = tex.coords[34][3];
		tex.X1[5] = tex.coords[34][0];tex.X2[5] = tex.coords[34][1];tex.Y1[5] = tex.coords[34][2];tex.Y2[5] = tex.coords[34][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}																			
	//Tree
	if (texture == 35)
		{
		tex.X1[0] = tex.coords[35][0];tex.X2[0] = tex.coords[35][1];tex.Y1[0] = tex.coords[35][2];tex.Y2[0] = tex.coords[35][3];
		tex.X1[1] = tex.coords[35][0];tex.X2[1] = tex.coords[35][1];tex.Y1[1] = tex.coords[35][2];tex.Y2[1] = tex.coords[35][3];
		tex.X1[2] = tex.coords[35][0];tex.X2[2] = tex.coords[35][1];tex.Y1[2] = tex.coords[35][2];tex.Y2[2] = tex.coords[35][3];
		tex.X1[3] = tex.coords[35][0];tex.X2[3] = tex.coords[35][1];tex.Y1[3] = tex.coords[35][2];tex.Y2[3] = tex.coords[35][3];
		tex.X1[4] = tex.coords[35][0];tex.X2[4] = tex.coords[35][1];tex.Y1[4] = tex.coords[35][2];tex.Y2[4] = tex.coords[35][3];
		tex.X1[5] = tex.coords[35][0];tex.X2[5] = tex.coords[35][1];tex.Y1[5] = tex.coords[35][2];tex.Y2[5] = tex.coords[35][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}	
	//Tree
	if (texture == 36)
		{
		tex.X1[0] = tex.coords[36][0];tex.X2[0] = tex.coords[36][1];tex.Y1[0] = tex.coords[36][2];tex.Y2[0] = tex.coords[36][3];
		tex.X1[1] = tex.coords[36][0];tex.X2[1] = tex.coords[36][1];tex.Y1[1] = tex.coords[36][2];tex.Y2[1] = tex.coords[36][3];
		tex.X1[2] = tex.coords[36][0];tex.X2[2] = tex.coords[36][1];tex.Y1[2] = tex.coords[36][2];tex.Y2[2] = tex.coords[36][3];
		tex.X1[3] = tex.coords[36][0];tex.X2[3] = tex.coords[36][1];tex.Y1[3] = tex.coords[36][2];tex.Y2[3] = tex.coords[36][3];
		tex.X1[4] = tex.coords[36][0];tex.X2[4] = tex.coords[36][1];tex.Y1[4] = tex.coords[36][2];tex.Y2[4] = tex.coords[36][3];
		tex.X1[5] = tex.coords[36][0];tex.X2[5] = tex.coords[36][1];tex.Y1[5] = tex.coords[36][2];tex.Y2[5] = tex.coords[36][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}																			
	//Tree
	if (texture == 37)
		{
		tex.X1[0] = tex.coords[37][0];tex.X2[0] = tex.coords[37][1];tex.Y1[0] = tex.coords[37][2];tex.Y2[0] = tex.coords[37][3];
		tex.X1[1] = tex.coords[37][0];tex.X2[1] = tex.coords[37][1];tex.Y1[1] = tex.coords[37][2];tex.Y2[1] = tex.coords[37][3];
		tex.X1[2] = tex.coords[37][0];tex.X2[2] = tex.coords[37][1];tex.Y1[2] = tex.coords[37][2];tex.Y2[2] = tex.coords[37][3];
		tex.X1[3] = tex.coords[37][0];tex.X2[3] = tex.coords[37][1];tex.Y1[3] = tex.coords[37][2];tex.Y2[3] = tex.coords[37][3];
		tex.X1[4] = tex.coords[37][0];tex.X2[4] = tex.coords[37][1];tex.Y1[4] = tex.coords[37][2];tex.Y2[4] = tex.coords[37][3];
		tex.X1[5] = tex.coords[37][0];tex.X2[5] = tex.coords[37][1];tex.Y1[5] = tex.coords[37][2];tex.Y2[5] = tex.coords[37][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}	
		
	//Black 
	if (texture == 40)
		{
		tex.X1[0] = tex.coords[40][0];tex.X2[0] = tex.coords[40][1];tex.Y1[0] = tex.coords[40][2];tex.Y2[0] = tex.coords[40][3];
		tex.X1[1] = tex.coords[40][0];tex.X2[1] = tex.coords[40][1];tex.Y1[1] = tex.coords[40][2];tex.Y2[1] = tex.coords[40][3];
		tex.X1[2] = tex.coords[40][0];tex.X2[2] = tex.coords[40][1];tex.Y1[2] = tex.coords[40][2];tex.Y2[2] = tex.coords[40][3];
		tex.X1[3] = tex.coords[40][0];tex.X2[3] = tex.coords[40][1];tex.Y1[3] = tex.coords[40][2];tex.Y2[3] = tex.coords[40][3];
		tex.X1[4] = tex.coords[40][0];tex.X2[4] = tex.coords[40][1];tex.Y1[4] = tex.coords[40][2];tex.Y2[4] = tex.coords[40][3];
		tex.X1[5] = tex.coords[40][0];tex.X2[5] = tex.coords[40][1];tex.Y1[5] = tex.coords[40][2];tex.Y2[5] = tex.coords[40][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}	
	//White
	if (texture == 41)
		{
		tex.X1[0] = tex.coords[41][0];tex.X2[0] = tex.coords[41][1];tex.Y1[0] = tex.coords[41][2];tex.Y2[0] = tex.coords[41][3];
		tex.X1[1] = tex.coords[41][0];tex.X2[1] = tex.coords[41][1];tex.Y1[1] = tex.coords[41][2];tex.Y2[1] = tex.coords[41][3];
		tex.X1[2] = tex.coords[41][0];tex.X2[2] = tex.coords[41][1];tex.Y1[2] = tex.coords[41][2];tex.Y2[2] = tex.coords[41][3];
		tex.X1[3] = tex.coords[41][0];tex.X2[3] = tex.coords[41][1];tex.Y1[3] = tex.coords[41][2];tex.Y2[3] = tex.coords[41][3];
		tex.X1[4] = tex.coords[41][0];tex.X2[4] = tex.coords[41][1];tex.Y1[4] = tex.coords[41][2];tex.Y2[4] = tex.coords[41][3];
		tex.X1[5] = tex.coords[41][0];tex.X2[5] = tex.coords[41][1];tex.Y1[5] = tex.coords[41][2];tex.Y2[5] = tex.coords[41][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);
		}		
		
	if (texture > 41)
		{
		tex.X1[0] = tex.coords[texture][0];tex.X2[0] = tex.coords[texture][1];tex.Y1[0] = tex.coords[texture][2];tex.Y2[0] = tex.coords[texture][3];
		tex.X1[1] = tex.coords[texture][0];tex.X2[1] = tex.coords[texture][1];tex.Y1[1] = tex.coords[texture][2];tex.Y2[1] = tex.coords[texture][3];
		tex.X1[2] = tex.coords[texture][0];tex.X2[2] = tex.coords[texture][1];tex.Y1[2] = tex.coords[texture][2];tex.Y2[2] = tex.coords[texture][3];
		tex.X1[3] = tex.coords[texture][0];tex.X2[3] = tex.coords[texture][1];tex.Y1[3] = tex.coords[texture][2];tex.Y2[3] = tex.coords[texture][3];
		tex.X1[4] = tex.coords[texture][0];tex.X2[4] = tex.coords[texture][1];tex.Y1[4] = tex.coords[texture][2];tex.Y2[4] = tex.coords[texture][3];
		tex.X1[5] = tex.coords[texture][0];tex.X2[5] = tex.coords[texture][1];tex.Y1[5] = tex.coords[texture][2];tex.Y2[5] = tex.coords[texture][3];
		tex.mat[3] = 1;
		glMaterialfv(GL_FRONT,GL_EMISSION,tex.ems);
		glMaterialfv(GL_FRONT,GL_SPECULAR,tex.mat);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,tex.mat);																																							
		}
		
		
}
//-------------------------------------------------------------------------------------------------------
void LoadTextures(void)
{

	//Load Textures
	int  bufsize = sizeof(pathbuf);
	float image[512][512][4];
	glGenTextures(2,tex.IDs);

 	//Get Path
	GetPath("/Users/gijs/Genesis/mycraft/data/textures/azure_terrain.tex");
	fprintf(stderr,"Selected Path: %s\n",loadName);
	stream = fopen(loadName,"r");
	for (l=0;l<4;l++)
		{for (i=0;i<512;i++)
			{for (j=0;j<512;j++)
				{fread(fbuf,1,4,stream);
				 image[i][j][l] = fbuf[0];}}}
	fclose(stream);
	glBindTexture(GL_TEXTURE_2D,tex.IDs[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 512, 512, 0, GL_RGBA, GL_FLOAT, image);	

	GetPath("/Users/gijs/Genesis/mycraft/data/textures/azure_terrain_simple.tex");
	fprintf(stderr,"Selected Path: %s\n",loadName);
	stream = fopen(loadName,"r");
	for (l=0;l<4;l++)
		{for (i=0;i<512;i++)
			{for (j=0;j<512;j++)
				{fread(fbuf,1,4,stream);
				 image[i][j][l] = fbuf[0];}}}
	fclose(stream);
	glBindTexture(GL_TEXTURE_2D,tex.IDs[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 512, 512, 0, GL_RGBA, GL_FLOAT, image);	


	//Coordinates
	count = 0;
	for (i=0;i<512;i=i+32)
		{
		for (j=0;j<512;j=j+32)
			{
			x = (float)i / 512;
			y = (float)j / 512;
			tex.coords[count][0] = x;
			tex.coords[count][2] = y;
			x = (float) (i+32) / 512;
			y = (float) (j+32) / 512;
			tex.coords[count][1] = x;
			tex.coords[count][3] = y;
			count++;
			}
		}



}
//-------------------------------------------------------------------------------------------------------
