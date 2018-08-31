#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

int dxball,dyball;
int dx=0,dy=5;
int X=0,Y=0;
bool play=false,gameOver=false,pause=true;


struct enemy{
	int enx;
	int eny;
}enemies[10];

void exit()
{
	for(int i=0; i<10;i++)
	{
		if((enemies[i].enx<=X+dx+40 && enemies[i].enx>=X+dx)	&& (enemies[i].eny<=85 && enemies[i].eny>=5) || ( enemies[i].enx+30<=X+dx+40 && enemies[i].enx+30>=X+dx)	&& (enemies[i].eny<=85 && enemies[i].eny>=5)
			|| (enemies[i].enx<=X+dx+40 && enemies[i].enx>=X+dx)	&& (enemies[i].eny+60<=85 && enemies[i].eny+60>=5) || ( enemies[i].enx+30<=X+dx+40 && enemies[i].enx+30>=X+dx)	&& (enemies[i].eny+60<=85 && enemies[i].eny+60>=5)
			)
		{
			
			iPauseTimer(0);
			play=false;
			gameOver=true;
			pause=true;
		
		}
	}
}

void change()
{
	if(play){
	for(int i=0; i<10;i++)
	{
		enemies[i].eny--;
		if(enemies[i].eny== -60)
		{
			enemies[i].eny=400;
			enemies[i].enx=rand()%400;
		}
	}
	exit();
	}
}

#endif // MYHEADER_H_INCLUDED