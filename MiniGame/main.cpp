
# include "iGraphics.h"
int mposx,  mposy;
int x = 500, y = 50;
int dx=10, dy=10,r,g,b;
int xb = x - 50, yb = y - 20, dxb = 100, dyb = 10;
bool start=false ;

void change();
void restart();

//char bg[3][40] = { "background//new1.bmp", "background//new2.bmp", "background//new3.bmp" };
int i = 0;

void iDraw()
{

	iClear();
	//iShowBMP(0, 0, bg[i]);
	iSetColor(255,0,0);
	iFilledRectangle(0,0,1000,600);
	
	iSetColor(r, g, b);
	iFilledCircle(x, y, 10, 2500);
	iSetColor(255,255,255);
	iFilledRectangle(xb, yb, dxb, dyb);
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouse(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == ' ')
	{
		start = true;
	}
		if (key == 'a')
		{
			if (xb != 0)
			{
				xb -= 10;
				if (!start)
				{
					x -= 10;
				}
			}
		}
	
	
		if (key == 'd')
	{
		 if (xb != 900)
		{
		xb += 10;
		if (!start)
		{
			x += 10;
		}
		}
	}
	
	
}


void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_INSERT)
	{
		i = 1;
	}
	if (key == GLUT_KEY_HOME)
	{
		i = 2;
	}
	if (key == GLUT_KEY_END)
	{
		i = 0;
	}

	//place your codes for other keys here
}

void change()
{
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;
	if (start)
	{
		x += dx;
		y += dy;
		if (x >= iScreenWidth || x <= 0)
		{
			dx *= -1;
		}
		if (y >= iScreenHeight || y <= 0)
		{
			dy *= -1;
		}
		if (x >= xb && x <= xb + dxb && y >= yb && y <= yb + dyb)
		{
			dy *= -1;
		}
		if (y < yb)
		{
			
			restart();
		}
	}
	
}
void restart()
{
	x = 500; y = 50;
	dx = 10; dy = 10;
	xb = x - 50; yb = y - 20;
	start=false;
}

int main()
{
	iSetTimer(35, change);
	iInitialize(1000, 600, "demooo");
	return 0;
}
