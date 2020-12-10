#include<stdio.h>
#include<GL/glut.h>

int width = 600 , height = 600 , select = 0;
unsigned int TextureID[4];
unsigned char circle[64][64][4];
unsigned char waterwave[64][64][4];
unsigned char star[64][64][4];
unsigned char land[64][64][4];
/*----- Parameters of cube -----*/
int cube[6] = { 0 , 1 , 2 , 3 , 4 , 5 };
int face[][4] = { { 0 , 3 , 2 , 1 } , { 0 , 1 , 5 , 4 } , { 1 , 2 , 6 , 5 } , { 4 , 5 , 6 , 7 } , { 2 , 3 , 7 , 6 } , { 0 , 4 , 7 , 3 } };
float vertex[][3] = { { -0.5 ,  -0.5 , -0.5 } , { 0.5 , -0.5 , -0.5 } , { 0.5 , 0.5 , -0.5 } , { -0.5 , 0.5 , -0.5 } , { -0.5 , -0.5 , 0.5 } , { 0.5 , -0.5 , 0.5 } , { 0.5 , 0.5 , 0.5 } , { -0.5 , 0.5 , 0.5 } };
float normal[][3] = { { 0.0 , 0.0 , -1.0 } , { 0.0 , -1.0 , 0.0 } , { 1.0 , 0.0 , 0.0 } , { 0.0 , 0.0 , 1.0 } , { 0.0 , 1.0 , 0.0 } , { -1.0 , 0.0 , 0.0 } };
double color[6][3] = { { 0.55 ,0.55 , 0.25 } , { 0.65 , 0.55 , 1.0 } , { 0.75 , 0.55 , 0.55 } , { 0.55 , 0.55 , 0.25 } , { 0.7 , 0.6 , 0.7 } , { 0.55 , 0.75 , 0.75 } };
/*----- Parameters of light -----*/
float material_shininess = 32.0;
float light_position[] = { 0.0 , 15.0 , 5.0 , 1.0 };
float light_direction[] = { 0.0 , -1.0 , 0.0 , 0.0 };
float light_diffuse[] = { 1.0 , 1.0 , 0.5 , 1.0 };
float light_specular[] = { 0.5 , 0.5 , 0.5 , 1.0 };
float light_cutoff = 50.0;
double light_attenuation = 0.8;

void Create_Texture_Circle()
{
	int  y, x, i, temp;
	for(y=0;y<64;y++)
	{
		for(x=0;x<64;x++)
		{
			circle[y][x][0] = 100;
			circle[y][x][1] = 100;
			circle[y][x][2] = 100;
			circle[y][x][3] = 255;
		}
	}
	for(y=16,x=0;y<48;y++)
	{
		if(y<=20 && y>=17)
			x=x+2;
		else if(y==22 || y==25 || y==31)
			x=x+1;
		else if(y==42 || y==39 || y==33)
			x=x-1;
		else if(y<=47 && y>=44)
			x=x-2;
		temp=x;
		for(x=0;x<temp;x++)
		{
			circle[y][x][0] = 150;
			circle[y][x][1] = 150;
			circle[y][x][2] = 150;
			circle[y][x][3] = 255;
		}
		for(x=64-temp;x<64;x++)
		{
			circle[y][x][0] = 150;
			circle[y][x][1] = 150;
			circle[y][x][2] = 150;
			circle[y][x][3] = 255;
		}
		x=temp;
	}

	for(x=16,y=0;x<48;x++)
	{
		if(x<=20 && x>=17)
			y=y+2;
		else if(x==22 || x==25 || x==31)
			y=y+1;
		else if(x==42 || x==39 || x==33)
			y=y-1;
		else if(x<=47 && x>=44)
			y=y-2;
		temp=y;
		for(y=0;y<temp;y++)
		{
			circle[y][x][0] = 200;
			circle[y][x][1] = 200;
			circle[y][x][2] = 200;
			circle[y][x][3] = 255;
		}
		for(y=64-temp;y<64;y++)
		{
			circle[y][x][0] = 200;
			circle[y][x][1] = 200;
			circle[y][x][2] = 200;
			circle[y][x][3] = 255;
		}
		y=temp;
	}
	for(i=0;i<61;i++)
	{
		for(y=i;y<4+i;y++)
		{
			for(x=i;x<4+i;x++)
			{
				circle[y][x][0] = 255;
				circle[y][x][1] = 255;
				circle[y][x][2] = 255;
				circle[y][x][3] = 255;
			}
		}
	}
	for(i=0;i<61;i++)
	{
		for(y=i;y<4+i;y++)
		{
			for(x=60-i;x<64-i;x++)
			{
				circle[y][x][0] = 255;
				circle[y][x][1] = 255;
				circle[y][x][2] = 255;
				circle[y][x][3] = 255;
			}
		}
	}
}

void Create_Texture_Waterwave( )
{
	int x, y, i ;

	for( x=0 ; x<64 ; x++ )
		for( y=0 ; y<32 ; y++ )
		{
			waterwave[x][y][0] = 0 ;
			waterwave[x][y][1] = 100 ;
			waterwave[x][y][2] = 255 ;
			waterwave[x][y][3] = 255 ;
		}

	x = 0 ;	y = 4 ;
	while( y <= 28 )
	{
		for( i=x ; i<32 ; i++ )
		{
			waterwave[i][y][0] = 200 ;
			waterwave[i][y][1] = 255 ;
			waterwave[i][y][2] = 255 ;
			waterwave[i][y][3] = 255 ;
		}
		y ++ ;
		if( y < 9 )
			x += 3 ;
		else if( y == 9 )
			x ++ ;
		else if( y == 10 )
			x += 2 ;
		else if( y == 11 )
			x ++ ;
		else if( y == 12 )
			x += 2 ;
		else if( y == 13 )
			x ++ ;
		else if( y == 14 )
			x += 2 ;
		else if( y == 16 )
			x ++ ;
		else if( y == 19 )
			x ++ ;
		else if( y == 21 )
			x ++ ;
		else if( y == 23 )
			x ++ ;
		else if( y == 26 )
			x ++ ;
		else
			x ++ ;
	}
	x = 0 ;	y = 0 ;
	while( y <= 24 )
	{
		for( i=x ; i<32 ; i++ )
		{
			waterwave[i][y][0] = 0 ;
			waterwave[i][y][1] = 100 ;
			waterwave[i][y][2] = 255 ;
			waterwave[i][y][3] = 255 ;
		}
		y ++ ;
		if( y < 5 )
			x += 3 ;
		else if( y == 5 )
			x ++ ;
		else if( y == 6 )
			x += 2 ;
		else if( y == 7 )
			x ++ ;
		else if( y == 8 )
			x += 2 ;
		else if( y == 9 )
			x ++ ;
		else if( y == 10 )
			x += 2 ;
		else if( y == 11 )
			x ++ ;
		else if( y == 14 )
			x ++ ;
		else if( y == 16 )
			x ++ ;
		else if( y == 18 )
			x ++ ;
		else if( y == 21 )
			x ++ ;
		else
			x ++ ;
	}

	for( x=63 ; x>31 ; x-- )
		for( y=0 ; y<32 ; y++ )
			for( i=0 ; i<4 ; i++ )
				waterwave[x][y][i] = waterwave[63-x][y][i] ;

	for( y=32 ; y<64 ; y++ )
		for( x=0 ; x<64 ; x++ )
			for( i=0 ; i<4 ; i++ )
			{
				if( x >=47 )
					waterwave[x][y][i] = waterwave[x-47][y-32][i] ;
				else
					waterwave[x][y][i] = waterwave[x+16][y-32][i] ;
			}
}

void Create_Texture_Land( )
{
	int x, y, i ;

	for( y=0 ; y<32 ; y++ )
		for( x=0 ; x<32 ; x++ )
		{
			land[x][y][0] = 240 ;
			land[x][y][1] = 240 ;
			land[x][y][2] = 240 ;
			land[x][y][3] = 255 ;
		}


	for( x=24 ; x<32 ; x++ )
	{
		land[x][0][0] = 255 ;
		land[x][0][1] = 200 ;
		land[x][0][2] = 200 ;
		land[x][0][3] = 255 ;

		land[0][x][0] = 255 ;
		land[0][x][1] = 200 ;
		land[0][x][2] = 200 ;
		land[0][x][3] = 255 ;
	}
	for( x=26 ; x<32 ; x++ )
	{
		land[x][1][0] = 255 ;
		land[x][1][1] = 200 ;
		land[x][1][2] = 200 ;
		land[x][1][3] = 255 ;

		land[1][x][0] = 255 ;
		land[1][x][1] = 200 ;
		land[1][x][2] = 200 ;
		land[1][x][3] = 255 ;
	}
	for( x=27 ; x<32 ; x++ )
	{
		for( y=2 ; y<4 ; y++ )
		{
			land[x][y][0] = 255 ;
			land[x][y][1] = 200 ;
			land[x][y][2] = 200 ;
			land[x][y][3] = 255 ;

			land[y][x][0] = 255 ;
			land[y][x][1] = 200 ;
			land[y][x][2] = 200 ;
			land[y][x][3] = 255 ;
		}
	}
	for( x=28 ; x<32 ; x++ )
	{
		for( y=4 ; y<7 ; y++ )
		{
			land[x][y][0] = 255 ;
			land[x][y][1] = 200 ;
			land[x][y][2] = 200 ;
			land[x][y][3] = 255 ;

			land[y][x][0] = 255 ;
			land[y][x][1] = 200 ;
			land[y][x][2] = 200 ;
			land[y][x][3] = 255 ;
		}
	}
	for( x=29 ; x<32 ; x++ )
	{
		for( y=7 ; y<9 ; y++ )
		{
			land[x][y][0] = 255 ;
			land[x][y][1] = 200 ;
			land[x][y][2] = 200 ;
			land[x][y][3] = 255 ;

			land[y][x][0] = 255 ;
			land[y][x][1] = 200 ;
			land[y][x][2] = 200 ;
			land[y][x][3] = 255 ;
		}
	}
	for( x=30 ; x<32 ; x++ )
	{
		for( y=9 ; y<12 ; y++ )
		{
			land[x][y][0] = 255 ;
			land[x][y][1] = 200 ;
			land[x][y][2] = 200 ;
			land[x][y][3] = 255 ;

			land[y][x][0] = 255 ;
			land[y][x][1] = 200 ;
			land[y][x][2] = 200 ;
			land[y][x][3] = 255 ;
		}
	}
	for( x=31 ; x<32 ; x++ )
	{
		for( y=12 ; y<16 ; y++ )
		{
			land[x][y][0] = 255 ;
			land[x][y][1] = 200 ;
			land[x][y][2] = 200 ;
			land[x][y][3] = 255 ;

			land[y][x][0] = 255 ;
			land[y][x][1] = 200 ;
			land[y][x][2] = 200 ;
			land[y][x][3] = 255 ;
		}
	}

	for( y=16 ; y<32 ; y++ )
		for( x=16 ; x<32 ; x++ )
		{
			land[x][y][0] = 200 ;
			land[x][y][1] = 160 ;
			land[x][y][2] = 255 ;
			land[x][y][3] = 255 ;
		}
	for( y=20 ; y<32 ; y++ )
		for( x=20 ; x<32 ; x++ )
		{
			land[x][y][0] = 255 ;
			land[x][y][1] = 200 ;
			land[x][y][2] = 255 ;
			land[x][y][3] = 255 ;
		}

	for( x=63 ; x>31 ; x-- )
	{
		for( y=0 ; y<32 ; y++ )
			for( i=0 ; i<4 ; i++ )
				land[x][y][i] = land[63-x][y][i] ;
	}

	/* Create the rest half part */
	for( y=32 ; y<64 ; y++ )
		for( x=0 ; x<64 ; x++ )
			for( i=0 ; i<4 ; i++ )
				land[x][y][i] = land[x][63-y][i] ;
}

void Create_Texture_Star( )
{
	int x, y, i ;

	for( x=0 ; x<64 ; x++ )
		for( y=0 ; y<64 ; y++ )
		{
			star[x][y][0] = 255 ;
			star[x][y][1] = 255 ;
			star[x][y][2] = 255 ;
			star[x][y][3] = 255 ;
		}

	x = 31 ;	y = 60 ;
	while( x >= 12 )
	{
		for( i=y ; i>4 ; i-- )
		{
			star[x][i][0] = 100 ;
			star[x][i][1] = 100 ;
			star[x][i][2] = 255 ;
			star[x][i][3] = 255 ;
		}
		y -= 3 ;
		x-- ;
	}
	x = 31 ;	y = 20 ;
	while( x >= 12 )
	{
		for( i=y ; i>4 ; i-- )
		{
			star[x][i][0] = 255 ;
			star[x][i][1] = 255 ;
			star[x][i][2] = 255 ;
			star[x][i][3] = 255 ;
		}
		y -= 1 ;
		x-- ;
	}
	x = 4 ;	y = 40 ;
	while( y >= 18 )
	{
		for( i=x ; i<32 ; i++ )
		{
			star[i][y][0] = 100 ;
			star[i][y][1] = 100 ;
			star[i][y][2] = 255 ;
			star[i][y][3] = 255 ;
		}
		y -= 1 ;
		if( (y % 2)== 1 )
			x += 2 ;
		else
			x++ ;
	}

	for( x=63 ; x>31 ; x-- )
		for( y=0 ; y<64 ; y++ )
			for( i=0 ; i<4 ; i++ )
				star[x][y][i] = star[63-x][y][i] ;
}

void Draw_UnitCube( int index )
{
	glTexEnvf( GL_TEXTURE_ENV , GL_TEXTURE_ENV_MODE , GL_MODULATE );
	glBindTexture( GL_TEXTURE_2D , TextureID[index] );
	glMatrixMode( GL_TEXTURE );
	glLoadIdentity( );
	glMatrixMode( GL_MODELVIEW);
	for( int i=0 ; i<6 ; i++ )
	{
		glNormal3fv( normal[i] );
		glColor3dv( color[i] );
		glBegin( GL_POLYGON );
			glTexCoord2f( 0.0 , 0.0 );
			glVertex3fv( vertex[face[i][0]] );
			glTexCoord2f( 0.0 , 8.0 );
			glVertex3fv( vertex[face[i][1]] );
			glTexCoord2f( 8.0 , 8.0 );
			glVertex3fv( vertex[face[i][2]] );
			glTexCoord2f( 8.0 , 0.0 );
			glVertex3fv( vertex[face[i][3]] );
		glEnd();
	}
}

void Initial( )
{
	glShadeModel( GL_SMOOTH );
	glEnable( GL_DEPTH_TEST );
	glEnable( GL_NORMALIZE );
	glEnable( GL_TEXTURE_2D );
	glGenTextures( 4 , TextureID );

	Create_Texture_Circle( );
	glPixelStorei( GL_UNPACK_ALIGNMENT , 4 );
	glBindTexture( GL_TEXTURE_2D , TextureID[0] );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );
	glTexImage2D( GL_TEXTURE_2D , 0 , GL_RGBA , 64 , 64 , 0 , GL_RGBA , GL_UNSIGNED_BYTE , circle );

	Create_Texture_Star( );
	glPixelStorei( GL_UNPACK_ALIGNMENT , 4 );
	glBindTexture( GL_TEXTURE_2D , TextureID[1] );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );
	glTexImage2D( GL_TEXTURE_2D , 0 , GL_RGBA , 64 , 64 , 0 , GL_RGBA , GL_UNSIGNED_BYTE , star );

	Create_Texture_Land( );
	glPixelStorei( GL_UNPACK_ALIGNMENT , 4 );
	glBindTexture( GL_TEXTURE_2D , TextureID[2] );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );
	glTexImage2D( GL_TEXTURE_2D , 0 , GL_RGBA , 64 , 64 , 0 , GL_RGBA , GL_UNSIGNED_BYTE , land );

	Create_Texture_Waterwave( );
	glPixelStorei( GL_UNPACK_ALIGNMENT , 4 );
	glBindTexture( GL_TEXTURE_2D , TextureID[3] );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );
	glTexImage2D( GL_TEXTURE_2D , 0 , GL_RGBA , 64 , 64 , 0 , GL_RGBA , GL_UNSIGNED_BYTE , waterwave );

	glEnable( GL_LIGHTING );
	glEnable( GL_LIGHT0 );
	glLightfv( GL_LIGHT0 , GL_POSITION , light_position );
	glLightfv( GL_LIGHT0 , GL_SPOT_DIRECTION , light_direction );
	glLightf( GL_LIGHT0 , GL_SPOT_CUTOFF , light_cutoff );
	glLightfv( GL_LIGHT0 , GL_DIFFUSE , light_diffuse );
	glLightfv( GL_LIGHT0 , GL_SPECULAR , light_specular );
	glLightf( GL_LIGHT0 , GL_CONSTANT_ATTENUATION , light_attenuation );
	glMaterialf( GL_FRONT , GL_SHININESS , material_shininess );
	glEnable( GL_COLOR_MATERIAL );
	glColorMaterial( GL_FRONT , GL_SPECULAR );
	glColor3f( 1.0 , 1.0 , 1.0 );
	glColorMaterial( GL_FRONT , GL_DIFFUSE );

	printf( "Press space to change texture map\n" );
	printf( "Press q to exit program\n" );
}

void Display( )
{
	glClearColor( 0.0 , 0.0 , 0.0 , 1.0 );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity( );
	gluLookAt( 0.0 , 4.0 , 14.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 );
    glViewport( 0 , 0 , width , height );
	glPushMatrix( );
		glTranslated( 0.0 , -3.0 , 0.0 );
		glScalef( 10.0 , 1.0 , 10.0 );
		glRotatef( 45.0 , 0.0 , 1.0 , 0.0 );
		Draw_UnitCube( select );
	glPopMatrix( );
	glutSwapBuffers( );
	glFlush( );
}

void Reshape( int w , int h )
{
	width = w;
	height = h;
	glViewport( 0 , 0 , w , h );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	gluPerspective( 90.0 , (double)width/(double)height , 0.5 , 200.0 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );
}

void Keyboard( unsigned char key , int x , int y )
{
	if( key=='Q' || key=='q' )
		exit( 0 );
	if( key == ' ' )
		select = ( select + 1 ) % 4;
	Display( );
}

void main( )
{
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize( width , height );
	glutCreateWindow( "CircleTexture" );
	Initial( );
	glutDisplayFunc( Display );
	glutReshapeFunc( Reshape );
	glutKeyboardFunc( Keyboard );
	glutMainLoop( );
}
