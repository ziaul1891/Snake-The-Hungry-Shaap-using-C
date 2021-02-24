
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>


void start_game();
void menu();
void level_two();
void instruction();
void about();
void load();
void check();
void gameover();
void finish();
void mazecheck1();
int a[200],b[200],total=5,temp,z,i,j,t,p,q,lv=0,dly=120;

int score=0;


void main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "C://turboc3//bgi");
	load();
	menu();
	closegraph();
}





void load()
{
	 outtextxy(100,100,"Press a to proceed");
	 outtextxy(100,200,"Press any key to twice to directly enter the menu");

	int ch=getch();
	int k;

	if(ch=='a'||ch=='A')
	{

	 cleardevice();

	   for(k=0;k<400;k+=2)
	{

		setcolor(CYAN);
		setfillstyle(SOLID_FILL,BLUE);
		circle(320,240,2+k);
		floodfill(320,240,CYAN);
		/*
		setfillstyle(SOLID_FILL,BLUE);
		bar(310-k,220-k,330+k,240+k);

		delay(50);
		*/
	}

     /*
	 for(k=0;k<300;k+=9)
	{
	 setcolor(YELLOW);
	 setfillstyle(SOLID_FILL,BLUE);
	 circle(320,240,2+k);
	 floodfill(320,240,YELLOW);

	 delay(50);
	 }






    for(k=0;k<150;k+=9)
    {
	setcolor(GREEN);
	setfillstyle(SOLID_FILL,BLUE);
	circle(320,240,2+k);
	floodfill(320,240,GREEN);

	delay(70);
    }

    */
    for(k=0;k<350;k+=9)
    {

	setfillstyle(SOLID_FILL,BLACK);
	bar(310-k,220-k,330+k,240+k);

	delay(50);

    }

	cleardevice();
	setcolor(BROWN);
	settextstyle(3,0,8);
	outtextxy(220,70,"Snake");
	delay(200);



	setcolor(GREEN);
	settextstyle(7,0,4);
	outtextxy(160,200,"The Hungry Shaap");
	setcolor(YELLOW);
	delay(200);



	settextstyle(3,0,1);
	outtextxy(283,298,"Loading...");

	for(i=0; i<625; i+=5)
	{
		setfillstyle(SOLID_FILL,GREEN);
		sector(2+i,390,0,45,8,8);
		delay(20);

	}


       /*
	while(1)
	{
		setcolor(CYAN);
		settextstyle(6,0,3);
		outtextxy(3,410,"Press any key to continue...");
		delay(200);

		setcolor(BLACK);
		settextstyle(6,0,3);
		outtextxy(3,410,"Press any key to continue...");
		delay(200);

		if(kbhit())
		break;
	}
	*/


    }
	setcolor(GREEN);
	settextstyle(2,0,5);
	outtextxy(3,410,"Press any key to continue...");
	getch();
	cleardevice();
}



void menu()

{

	int n=190;
	char ch;
	int flag=0;
	while(1)
	{




		setfillstyle(SOLID_FILL,3);
		bar(20,20,620,30);
		bar(20,20,30,460);
		bar(20,450,620,460);
		bar(610,20,620,460);


		setcolor(10);
		settextstyle(0,0,3);
		outtextxy(65,90,"Snake The Hungry Shaap");

		setcolor(CYAN);
		settextstyle(TRIPLEX_FONT,0,3);
		line(240,n,240+175,n);


				circle(221,n,7);
				circle(235,n,5);
				circle(421,n,5);
				circle(435,n,7);



		outtextxy(260,160,"Start Game");
		settextstyle(TRIPLEX_FONT,0,3);
		outtextxy(265,200,"Instruction");
		settextstyle(TRIPLEX_FONT,0,3);
		outtextxy(295,240,"About");
		settextstyle(TRIPLEX_FONT,0,3);
		outtextxy(300,280,"Exit");

		if(kbhit())

		{
			ch=getch();
			if(ch==80 && n<280)
			{

		    line(240,n,240+175,n);
		    circle(221,n,7);
		    circle(235,n,5);
		    circle(421,n,5);
		    circle(435,n,7);
		    n+=40;

		    flag++;

	    }


			if(ch==72 && n>200)
			{

				line(240,n,240+175,n);
				circle(221,n,7);
				circle(235,n,5);
				circle(421,n,5);
				circle(435,n,7);
				n-=40;
				flag--;

			}

			if(ch==27)
			exit(1);

			if(ch==13 && flag==0)
			{

				start_game();
				cleardevice();
			}

			cleardevice();

			if(ch==13 && flag==1)
			{

			cleardevice();
			instruction();

			}

			if(ch==13 && flag==2)

			{

			cleardevice();
			about();

			}

			if(ch==13 && flag==3)
			exit(1);



		}


	}

	cleardevice();
}

void about()
{

    cleardevice();

    for(int h=0;h<260;h++)
    {
	cleardevice();
	setcolor(RED);
	settextstyle(0,0,3);
	outtextxy(300-h,140," Snake The Hungry Shaap ");
	settextstyle(0,0,2);
	outtextxy(20+h,220, " Created by: Zia");
	outtextxy(209+h,240," Badhon ");
	outtextxy(209+h,260," Mahi ");

    }
	settextstyle(2,0,4);
	outtextxy(220,340,"This program was created in Turbo C");
	outtextxy(300,360,"@ 2013 @");

	getch();
	cleardevice();
}









void instruction()
{
    cleardevice();
    settextstyle(2,0,6);

    setcolor(YELLOW);
    outtextxy(20,120," 1. Use Arrow Keys To Direct The Snake ");
    outtextxy(20,140," 2. Avoid The Head Of Snake Not To Hit Any Part Of Snake");
    outtextxy(20,160," 3. Also Avoid The Head Of Snake Not To Hit Mazes");
    outtextxy(20,180," 4. Pick The Foods Until You Win The Game ");
    outtextxy(10,220,"LEVEL I has no obstacles, LEVEL II has Mazes ");
    outtextxy(10,240,"and LEVEL III will have a speedier snake every time it eats");
    outtextxy(10,270,"SO GOOD LUCK :) ");
    getch();
    cleardevice();
}




void level_two()
{

    setfillstyle(SOLID_FILL,3);
    bar(150,100,250,120);
    setfillstyle(SOLID_FILL,3);
    bar(270,220,370,240);
    setfillstyle(SOLID_FILL,3);
    bar(350,350,500,370);

   /* if(score>=12)
    {
	setfillstyle(SOLID_FILL,BLACK);
	bar(150,100,250,120);
	setfillstyle(SOLID_FILL,BLACK);
	bar(270,220,370,240);
	setfillstyle(SOLID_FILL,BLACK);
	bar(350,350,500,370);

    } */
    if(p>=150&&q<=250&&q>=100&&q<=120)

    {

	p=rand() % 560+ 60;
	temp=p%13;
	p=p-temp;
	q=rand() % 380 + 60;
	temp=q%14;
	q=q-temp;

    }

    if(p>=270&&p<=370&&q>=220&&q<=240)
    {

	p=rand() % 560 + 60;
	temp=p%13;
	p=p-temp;
	q=rand() % 380 + 60;
	temp=q%14;
	q=q-temp;
    }

    if(p>=350&&p<=500&&q>=350&&q<=370)
    {

	p=rand() % 560 + 60;
	temp=p%13;
	p=p-temp;
	q=rand() % 380 + 60;
	temp=q%14;
	q=q-temp;

    }


}



void mazecheck1()
{

	if((a[0]>=150&&a[0]<=250&&b[0]>=100&&b[0]<=120)&&(score>=16&&score<=50))
	{
	    gameover();

		}
	if((a[0]>=350&&a[0]<=500&&b[0]>=350&&b[0]<=370)&&(score>=16&&score<=50))
	{
	    gameover();

		}
	if((a[0]>=270&&a[0]<=370&&b[0]>=220&&b[0]<=240)&&(score>=16&&score<=50))
	{
	    gameover();

		}


}



void start_game()

{

    int ch,maxx,maxy,x=52,y=42,p,q;
    cleardevice();
    maxx=getmaxx();
    maxy=getmaxy();

    //akdom prothom theke lekha ta ashar jonno
    gotoxy(1,1);
    printf("SCORE:");

    randomize();

    p=rand() % 560 + 60;
    temp=p%13;
    p=p-temp;
    q=rand() % 380 + 60;
    temp=q%14;
    q=q-temp;





    z=0,i=0;

while(1)
{



	if(score>=0&&score<=16){
		setcolor(RED);
		settextstyle(2,0,5);
		outtextxy(560,1,"LEVEL I");

	}
	if(score>=16&&score<=30){
		setcolor(RED);
		settextstyle(2,0,5);
		outtextxy(560,1,"LEVEL II");

	}
	if(score>=30&&score<=50){
		setcolor(RED);
		settextstyle(2,0,5);
		outtextxy(560,1,"LEVEL III");

	}



       /*	setfillstyle(SOLID_FILL,3);
		bar(20,20,620,30);
		bar(20,20,30,460);
		bar(20,450,620,460);
		bar(610,20,620,460); */



	setcolor(WHITE);
	setfillstyle(SOLID_FILL,RED);
	circle(p,q,5);
	floodfill(p,q,WHITE);



	if(kbhit())

       {
		ch=getch();
		if(ch==0)
		ch=getch();


		if(ch==72&& z!=2)
		{
			z=1;
		}


		if(ch==80&& z!=1)
		{
			 z=2;
		}


		if(ch==75&& z!=4)
		{
			 z=3;
		}


		if(ch==77&& z!=3)
		{
			 z=4;
		}


	}


   else
	{
		if(ch==27)
			break;

	}




	if(i<20)
	{
		a[i]=x;
		b[i]=y;
		i++;
	}




     if(i>=20)

	{
	  for(j=total;j>=0;j--)
	  {
	       a[1+j]=a[j];
	       b[1+j]=b[j];
	  }


	  a[0]=x;
	  b[0]=y;





	setcolor(WHITE);
	setfillstyle(SOLID_FILL,BLUE);
	circle(a[0],b[0],6);
	floodfill(a[0],b[0],WHITE);


	setcolor(WHITE);
	for(j=1;j<total;j++)

     {
	setfillstyle(SOLID_FILL,GREEN);
	circle(a[j],b[j],5);
	floodfill(a[j],b[j],WHITE);
}

    delay(dly);



    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BLACK);
    circle(a[0],b[0],6);
    floodfill(a[0],b[0],BLACK);



    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BLACK);
    circle(a[j],b[j],5);
    floodfill(a[j],b[j],BLACK);


}



    check();




    if(x==p&&y==q)

    {
	if(score>=30)
	{

		cleardevice();
		if(dly>=50)
		dly=dly-10;
		else dly=50;
	}

	total=total+1;

	score=score+2;


	setcolor(RED);


	 gotoxy(1,1);
	 printf("SCORE: %d",score);


    if(total>28)
	{
		finish();
	}

	p=rand() % 560 + 60;
	temp=p%13;
	p=p-temp;
	q=rand() % 380 + 60;
	temp=q%14;
	q=q-temp;

    }

    if(score>=16 && score<=50)
    {

	if(lv==0)
	{

	    setfillstyle(SOLID_FILL,3);
	    bar(150,100,250,120);
	    setfillstyle(SOLID_FILL,3);
	    bar(270,220,370,240);
	    setfillstyle(SOLID_FILL,3);
	    bar(350,350,500,370);


	    setcolor(GREEN);
	    settextstyle(3,0,5);
	    outtextxy(270,130,"LEVEL 2");



	    getch();

	    setcolor(BLACK);
	    settextstyle(3,0,5);
	    outtextxy(270,130,"LEVEL 2");



	    lv=1;
	}
    if(score>=30){

	    if(lv==1){
	     setcolor(GREEN);
	    settextstyle(3,0,5);
	    outtextxy(270,130,"LEVEL 3");



	    getch();

	    setcolor(BLACK);
	    settextstyle(3,0,5);
	    outtextxy(270,130,"LEVEL 3");
	    lv=2;
	}




    }




    level_two();

}


   if(z==1)
	y = y-14;

   if(y<28)
   {

    temp=maxy%14;
    y=maxy-temp;
   }

   if(z==2)
   {
    y=y+14;
   }


   if(y>maxy)
   {
    y=28;
   }


   if(z==3)
   {
    x=x-13;
   }


   if(x<0)
   {
    temp=maxx%13;
    x=maxx-temp;
   }


   if(z==4)
   {
       x = x+13;
   }


   if(x>maxx)

   {
	 x=0;
   }


   if(z==0)
   {
   // y=y+14 ;
	x=x+13;
   }

 }

}




void check()

{

	int p;
	for(p=1;p<total;p++)
	{

	if(a[0]==a[p] && b[0]==b[p])
	{
		gameover();
	}



	else
	{
	  continue;
	}
    }

    mazecheck1();
}



void gameover()
{

	for(int g=0;g<6;g++)
	{
	     cleardevice();
	     setcolor(RED);
	     settextstyle(8,0,1+g);
	     outtextxy(120,230," GAME OVER ");
	     delay(70);
	}


	for(i=0;i<=40;i++)
	{

		circle(300,155,50);
		circle(280,150,5);
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,YELLOW);
		circle(280,150,2);
		floodfill(280,150,WHITE);
		circle(320,150,5);
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,YELLOW);
		circle(320,150,2);
		floodfill(320,150,WHITE);
		line(300,150,300,170);
		arc(300,200,80-i,100+i,20);
		delay(50);
	}
	settextstyle(2,0,5);
	outtextxy(170,350,"Press any key to exit the program");




/*
char ch=getch();
       if(ch==27||ch==13)
	   {
	   cleardevice();
	   menu();


	   }

*/

	getch();
	exit(0);

}





void finish()
{

	for(int fn=0;fn<6;fn++)
	{
		cleardevice();
		setcolor(GREEN);

		settextstyle(4,0,1+fn);
		outtextxy(170,230," YOU WIN ");
		delay(50);
	}

	for(i=0;i<=40;i++)
	{

		circle(300,155,50);
		circle(280,150,5);
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,YELLOW);
		circle(280,150,2);
		floodfill(280,150,WHITE);
		circle(320,150,5);
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,YELLOW);
		circle(320,150,2);
		floodfill(320,150,WHITE);
		line(300,150,300,170);
		arc(300,170,260-i,280+i,20);
		delay(50);
	}

	settextstyle(2,0,5);
	outtextxy(170,350,"Press any key to exit the program");
/*
char ch=getch();
       if(ch==27||ch==13)
	   {
	   cleardevice();
	   menu();
	   }
*/

	getch();
	exit(0);



}
