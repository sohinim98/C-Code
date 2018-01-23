#include<graphics.h>
#include<dos.h>
#include<stdio.h>
void mainscreenin1list(int sx,int sy,int ex,int ey);
void mainscreenin2list(int sx,int sy,int ex,int ey);
void list();
void icons();
void iconindex(int x1,int y1, int x2, int y2);
void funct( int x,int y);


//mouse functions

union REGS i,o;
int initmouse();
void showmouseptr();
void restrictmouseptr();
void getmousepos();

//end of mouse functions


void main()
{
int gd=DETECT,gm;

initgraph(&gd,&gm,"e:\tc\bgi");
list();
getch();
}

void list()
{
int sx,sy,ex,ey,frequency, i=0,button, x,y;
sx=15;
sy=10;
ex=630;
ey=470;
mainscreenin1list(sx,sy,ex,ey);
mainscreenin2list(sx,sy,ex,ey);

setviewport(1,1,640,470,1);
if( initmouse()==0)
{
closegraph();
restorecrtmode();
printf("Mouse Driver is not loaded");
exit(1);
}
restrictmouseptr(10,10,620,460);
showmouseptr();
icons();
do
  {
  getmousepos(&button,&x,&y);

if((button&1)==1)
  {
	i=1;
  for(frequency=2000;frequency<5000;frequency++)
  sound(frequency);
   nosound();
  }
	if(i==1) break;
}
while(1);

funct(x,y);

}


void mainscreenin1list(int sx,int sy,int ex,int ey)
{
   setfillstyle(1,7);
   bar(sx,sy,ex,ey);
   setfillstyle(1,7);
   setcolor(15);
   line(sx,sy,sx,ey);
   line(sx,sy,ex,sy);
   line(sx,sy,sx,ey);
   line(sx,sy,ex,sy);
   setcolor(0);
   line(ex,sy,ex,ey);
   line(ex,sy,ex,ey);
   line(sx,ey,ex,ey);
   line(sx,ey,ex,ey);


   settextstyle(0,0,0);
   setfillstyle(1,1);
   bar(sx+2,sy+2,ex-2,sy+20);
   setcolor(13);
   settextstyle(8,0,1);
   outtextxy(sx+190,sy-5,"IC LIST");
   //for x
   setfillstyle(1,7);
   bar(ex-15,sy+4,ex-4,sy+15);
   setcolor(15);
   line(ex-15,sy+4,ex-4,sy+4);
   line(ex-15,sy+4,ex-15,sy+15);
   setcolor(0);
   line(ex-15,sy+15,ex-4,sy+15);
   line(ex-4,sy+4,ex-4,sy+15);
   setcolor(1);
   settextstyle(0,0,1);
   outtextxy(ex-13,sy+5,"x");
   setfillstyle(1,7);
}

void mainscreenin2list(int sx,int sy,int ex,int ey)
{
  sx=sx+15;
  sy=sy+24;
  ex=ex-17;
  ey=ey-9;
 setcolor(0);

   line(sx,sy,sx,ey);
   line(sx,sy,ex,sy);
   line(sx,sy,sx,ey);
   line(sx,sy,ex,sy);
   setcolor(15);
   line(ex,sy,ex,ey);
   line(ex,sy,ex,ey);
   line(sx,ey,ex,ey);
   line(sx,ey,ex,ey);


  }


void icons()
{
int x1,y1,a,x2;
x1=70;
y1=50;
x2=150;
a=14;

//increment of y=45 from previous y
//increment of the y=30 from the same value
settextstyle(1,0,2);
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"EXIT");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7401");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7402");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7404");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7408");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7410");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7411");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7426");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7427");
y1+=45;


//end of first column

//start of next column

x1+=150;
y1=50;
x2+=150;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7432");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7437");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7445");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7446");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7447");
y1+=45;

iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7474");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7475");
y1+=45;

iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7476");
y1+=45;

iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7483");
y1+=45;



//end of second column

//start of next column

x1+=150;
y1=50;
a=10;
x2+=160;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7485");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"7486");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"74106");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"74145");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"74148");
y1+=45;

iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"74151");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"74251");
y1+=45;

iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"74266");
y1+=45;

iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a-3,y1,"74445");
y1+=45;


//end of second column

//start of next column

x1+=150;
y1=50;
x2+=130;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"4001");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"4011");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"4012");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"4013");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"4069");
y1+=45;

iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"4081");
y1+=45;
iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"4518");
y1+=45;

iconindex(x1,y1,x2,y1+30);
outtextxy(x1+a,y1,"4520");
y1+=45;

iconindex(x1,y1,x2,y1+30);
setcolor(4);
outtextxy(x1+a,y1,"EXIT");
y1+=45;


}

void funct(int x, int y)
{

if(x>70&&x<150&&y>50&&y<80)
exit(0);
list();

}


//making icons

void iconindex(int x1,int y1, int x2, int y2)
{
setlinestyle(0,0,3);

setcolor(15);
line(x1,y1,x2,y1);
line(x1,y1,x1,y2);
setcolor(0);
line(x1,y2,x2,y2);
line(x2,y2,x2,y1);
}



//start of mouse declarations

initmouse()
{
i.x.ax=0;
int86(0x33,&i,&o);
return(o.x.ax);
}

void showmouseptr()
{
i.x.ax=1;
int86(0x33,&i,&o);
}

void restrictmouseptr(int x1, int y1, int x2, int y2)
{
i.x.ax=7;
i.x.cx=x1;
i.x.dx=x2;
int86(0x33,&i,&o);

i.x.ax=8;
i.x.cx=y1;
i.x.dx=y2;
int86(0x33,&i,&o);
}

 void getmousepos(int *button, int *x, int *y)
{

i.x.ax=3;
int86(0x33,&i,&o);
*button=o.x.bx;
*x=o.x.cx;
*y=o.x.dx;
}