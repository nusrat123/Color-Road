#include "iGraphics.h"
#include "bitmap_loader.h"

int ballx=600,bally=50;   //my ball x , y co ordinate
int bl1x=200,bl2x=600,bl3x=1000,bl1y=550,bl2y=550,bl3y=550;  //x, y co ordinate of 3 balls coming from the top 
int r1=255,g1=0,b1=0,r2=0,g2=255,b2=0,r3=0,g3=0,b3=255;   //RGB combination of 3 balls 
int r=0,g=255,b=0;   //RGB combination of my ball
bool gameOn=true,gameover=false;  //flag for checking 


//int background [50];
void iDraw()
{

	iClear();
	iSetColor(128,128,128);  //grey color for background
	iFilledRectangle(0,0,1200,800);
	//iShowImage(0 ,0 ,800 ,1200 , background[0]) ;
	
	//iSetColor(0,0,255);
	//iLine(400,0,400,800);
	//iLine(800,0,800,800);
	iSetColor(255,255,255);  //white color lines in the background
	iFilledRectangle(380,0,40,800);
	iFilledRectangle(780,0,40,800);

	iSetColor(r1,g1,b1);
	iFilledCircle(bl1x,bl1y,50,1000);  //ball 1
	iSetColor(r2,g2,b2);
	iFilledCircle(bl2x,bl2y,50,1000);  //ball 2
	iSetColor(r3,g3,b3);
	iFilledCircle(bl3x,bl3y,50,1000);  //ball 3
	iSetColor(r,g,b);
	iFilledCircle(ballx,bally,50,1000);  //my ball
	if (gameover)
	{
		iText(500,400,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);   //game over text
	}
}

/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	//place your codes here
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
		
}


void iKeyboard(unsigned char key)
{
	
}


void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_LEFT && ballx > 200)
		ballx=ballx-400;  //decrement of x co ordinate of my ball by pressing left key
	if(key == GLUT_KEY_RIGHT && ballx <1000)
		ballx=ballx+400;  //increment of y co ordinate of my ball by pressing right key
}
// function for changing the balls color
void colorChangingOfBalls(){
	int a;  //variable for checking
	int x=10;  //variable for loop
	while(x)
	{
	a=rand()%3;
	x--;
	}
	if(a==0)
	{
		r1=255,g1=0,b1=0;
	
		{
			r2=0,g2=0,b2=255;
			r3=0,g3=255,b3=0;  
		}

	}

	if(a==1)
	{
		r1=0,g1=255,b1=0;
		
		{
			r2=0,g2=0,b2=255;
			r3=255,g3=0,b3=0;
		}

	}

	if(a==2)
	{
		r1=0,g1=0,b1=255;
		/*while(b!=0 || b!=1)
		{
		b=rand()%3;
		}
		if(b==0)
		{
			r2=255,g2=0,b2=0;
			r3=0,g3=255,b3=0;
		}
		else*/
		{
			r2=0,g2=255,b2=0;
			r3=255,g3=0,b3=0;
		}

	}
}
//function for checking if the game is on or not
void gameOnCheck()
{
	if(g==255)
	{
		if(ballx==200 && g1==255)
			gameOn=true;
		else if(ballx==1000 && g3==255)
			gameOn=true;
		else if(ballx==600 && g2==255)
			
				//if(g2==255)
					gameOn=true;
				//else
					//gameOn=false;
			
			else
				gameOn=false;
	}

	if(r==255)
	{
		if(ballx==200 && r1==255)
			gameOn=true;
		else if(ballx==1000 && r3==255)
			gameOn=true;
		else if(ballx==600 && r2==255)
			
					gameOn=true;
			
			else
				gameOn=false;
	}

	if(b==255)
	{
		if(ballx==200 && b1==255)
			gameOn=true;
		else if(ballx==1000 && b3==255)
			gameOn=true;
		else if(ballx==600 && b2==255)
			
				
					gameOn=true;
			
			else
				gameOn=false;
	}
}
//function for changing my ball color
void randomMyBall()
{
	int a;  //variable for checking
	int x=10;  //variable for loop
	if(gameOn)
	{
		if(bl1y<0)
		{		gameOnCheck();
				while(x)
				{
				a=rand()%3;
				x--;
				}
				if(a==0)
				{r=255,g=0,b=0;}
				else if(a==1)
				{r=0,g=255,b=0;}
				else
				{r=0,g=0,b=255;}
			
			x=10;  //again initializing x for loop
			bl1y=800,bl2y=800,bl3y=800;  //again ball coming from the top
			//winCheck();
			colorChangingOfBalls();
		}
		//decrement of y co ordinates of balls to let them come down
		bl1y=bl1y-20; 
		bl2y=bl2y-20;
		bl3y=bl3y-20;
	}
	else
		gameover=true;
}


int main()
{

	iSetTimer(20,randomMyBall);  //calling randomMyBall funtion to change my ball color after 20 msec
	iInitialize(1200, 800, "Game part 1");  //screen height 1200, width 800

	//background [0] =iLoadImage("image\\road.png") ;

	return 0;
}
