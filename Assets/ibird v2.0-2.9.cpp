#include "iGraphics.h"
#include<stdio.h>
#include<math.h>
#include <windows.h>
bool musicon=true;
const float pi=acos(0)*2;
const float g=10;
//for scoring
char showscor[15]={0};
int scr;
typedef struct {
    char name[10];
    int score;
} high;
high arr[5];
int scor[5];
//
//for coordinates of the ball
float xball=75,yball=75;
//for angles
float ang;
float angle=pi*ang /180;
//
int con,con1,con2,con3,con4,con5,con6,con7,con8;
float xshow=100*cos(angle);
float yshow=100*sin(angle);
int check;
int changed;
//for time
float t=0,tcol,tmax,m,n;
// for velocities
int mapping,running;
int direction=1;
float v,vx,vy;
float vxi;
float vyi;
//for collision of the bird
//i want to build that in such a way that if the bird collide then the col variable will increase then such things happen
int col;
float x=xball,y=yball;
//start update
int startx,startdot;
//for birds
int bird=1, birdstate;
int consol,consolout,consol2out;
// dark mode sound on off music on off
int dark,sound,music;
//for pigs/gems
int gem1,gem2,gem3,gem4,gem5,gem6,gem7,gem8,gem9;
//for number of turns
int num;
int backgnd;
int level;
int removed[35];
void highscore()
{
    if(changed!=1)
    {
        for (int i=0;i<5;i++)
        {
            if(scr>arr[i].score)
            {
                arr[i+5]=arr[i+4];
                arr[i+4]=arr[i+3];
                arr[i+3]=arr[i+2];
                arr[i+2]=arr[i+1];
                arr[i+1]=arr[i];
                arr[i].score=scr;
                scanf("%s",arr[i].name);
                break;
            }
        }
        FILE *fp=fopen("high score.txt","w");
        for(int j=0;j<5;j++)
        {
            fprintf(fp,"%s %d\n%",arr[j].name,arr[j].score);
        }
        fclose(fp);
        changed=1;
        consol=1;
    }
}
void startdotupdate()
{
    if (consol==0)
    {
        startdot++;
        startdot=startdot%4;
    }
}
void startupdate()
{
    if(check == 0 || check ==2)
    {
        iPauseTimer(1);
    }
    if(consol==0)
    {
        startx+=4;
        //iPauseTimer(4);
        if(startx==1000)
        {
            iPauseTimer(2);
            iPauseTimer(3);
            //iResumeTimer(4);
            consol++;
        }
    }

}
void menumusic()
{
    if (musicon)
        PlaySound("media.io_Angry-Birds-Theme-Song-[AudioTrimmer.com].wav",NULL,SND_LOOP | SND_ASYNC);
    else
        PlaySound(NULL,NULL,SND_LOOP);
}
void mapp()
{
    if (direction==1)
    {
        mapping++;
        if(mapping==100)
        {
            direction=0;
        }
    }
    else if(direction==0)
    {
        mapping--;
        if(mapping==0)
        {
            direction=1;
        }
    }
    //v=mapping;
}
void projectile()//projectile with collision also has pigs
{
    if(check ==2)
    {
        if((abs(vx)>0.005 || abs(vy)>0.005) && xball>0 && xball<1250 && yball>5)
        {
            t=t+0.1;
            running=1;
            xball=x+vx*(t-tcol);
            yball=y+vy*(t-tcol)-0.5*g*(t-tcol)*(t-tcol);
            if(level==0)//this does not have the col 1 many col 2 and 1 col 4 and 2 col 3
            {
                if(xball>=558-10 && xball<=565+10)
                {
                    if (yball>=120-10 &&yball<=135+10  )
                    {
                        ;
                    }
                }
                //each and every obstacle
                if(xball >=560-10 && xball<=560+32+10 && removed[0]==0)
                {
                    if(yball>=20-10 && yball<= 20+16+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[0]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=610-10 && xball<=610+20+10 && removed[1]==0)
                {
                    if(yball>=20-10 && yball<= 40+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[1]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=560-10 && xball<=560+65+10 && removed[2]==0)
                {
                    if(yball>=35-10 && yball<= 35+10+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/4;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[2]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=580-10 && xball<=580+16+10 && removed[3]==0)
                {
                    if(yball>=45-10 && yball<= 45+32+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/4;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[3]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=579-10 && xball<=579+20+10 && removed[4]==0)
                {
                    if(yball>=77-10 && yball<= 77+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[4]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=710-10 && xball<=710+32+10 && removed[5]==0)
                {
                    if(yball>=20-10 && yball<= 20+16+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[5]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=760-10 && xball<=760+20+10 && removed[6]==0)
                {
                    if(yball>=20-10 && yball<= 40+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[6]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=710-10 && xball<=710+65+10 && removed[7]==0)
                {
                    if(yball>=35-10 && yball<= 45+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/4;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[7]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=730-10 && xball<=730+16+10 && removed[8]==0)
                {
                    if(yball>=45-10 && yball<= 45+32+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/4;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[8]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=729-10 && xball<=729+20+10 && removed[9]==0)
                {
                    if(yball>=77-10 && yball<= 77+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[9]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=560-10 && xball<=560+36+10 && removed[10]==0)
                {
                    if(yball>=132-10 && yball<= 132+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[10]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=560-10 && xball<=560+36+10 && removed[11]==0)
                {
                    if(yball>=148-10 && yball<= 148+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[11]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=560-10 && xball<=560+36+10 && removed[12]==0)
                {
                    if(yball>=164-10 && yball<= 164+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[12]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=560-10 && xball<=560+36+10 && removed[13]==0)
                {
                    if(yball>=180-10 && yball<= 180+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[13]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=652-10 && xball<=652+36+10 && removed[14]==0)
                {
                    if(yball>=132-10 && yball<= 132+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[14]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=652-10 && xball<=652+36+10 && removed[15]==0)
                {
                    if(yball>=148-10 && yball<= 148+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[15]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=652-10 && xball<=652+36+10 && removed[16]==0)
                {
                    if(yball>=164-10 && yball<= 164+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[16]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=652-10 && xball<=652+36+10 && removed[17]==0)
                {
                    if(yball>=180-10 && yball<= 180+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[17]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=590-10 && xball<=590+70+10 && removed[18]==0)
                {
                    if(yball>=200-10 && yball<= 200+10+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[18]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=744-10 && xball<=744+36+10 && removed[19]==0)
                {
                    if(yball>=132-10 && yball<= 132+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[19]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=744-10 && xball<=744+36+10 && removed[20]==0)
                {
                    if(yball>=148-10 && yball<= 148+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[20]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=744-10 && xball<=744+36+10 && removed[21]==0)
                {
                    if(yball>=164-10 && yball<= 164+20+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[21]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=744-10 && xball<=744+36+10 && removed[22]==0)
                {
                    if(yball>=180-10 && yball<= 180+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[22]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=682-10 && xball<=682+70+10 && removed[23]==0)
                {
                    if(yball>=200-10 && yball<= 200+10+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[23]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if (xball>=570-10 && xball <=570+221+10 && col!=3)
                {
                    if (yball >=120-10 && yball <=120+15+10)
                    {
                        col=3;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=-(vy-g*(t-tcol))/2;
                        tcol=t;
                    }
                }
                if (yball<=20+15 && col!=3)
                {
                    col=3;
                    x=xball;
                    y=yball;
                    vx=vx/1.2;
                    vy=-(vy-g*(t-tcol))/2;
                    tcol=t;
                }
                if (xball>=558-10 && xball <=570+10 && col!=4)
                {
                    if (yball >=120-10 && yball <=120+15+10)
                    {
                        col=4;
                        x=xball;
                        y=yball;
                        vx=-vx/4;
                        vy=-(vy-g*(t-tcol))/4;
                        tcol=t;

                    }
                }
                if(col==3)
                {
                    if(xball<=570-10 || xball>=570+221+10 || yball<120-10 || yball>120+15+10)
                    {
                        if(yball>=35)
                            col=0;
                    }
                }
                if(xball >=750-10 && xball<=750+25+10)
                {
                    if(yball>=45-10 && yball<=45+25+10)
                    {
                        if(gem1==0)
                        {
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                            gem1=1;
                        }

                    }

                    if (gem1!=1)
                        gem1=0;
                }

                if(xball >=600-10 && xball<=625+10)
                {
                    if(yball>=45-10 && yball<=45+25+10 )
                    {
                        if(gem2==0)
                        {
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                            gem2=1;
                        }
                    }
                    if (gem2!=1)
                        gem2=0;
                }
                if(xball >=695-10 && xball<=695+50+10)
                {
                    if(yball>=134-10 && yball<=134+45+10 )
                    {
                        if(gem3==0)
                        {
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                            gem3=1;
                        }
                    }
                    if (gem3!=1)
                        gem3=0;
                }
                if(xball >=600-10 && xball<=665+10)
                {
                    if(yball>=134-10 && yball<=134+45+10)
                    {
                        if(gem4==0)
                        {
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                            gem4=1;
                        }
                    }
                    if (gem4!=1)
                        gem4=0;
                }
                gem5=1;
                gem6=1;
            }
            if(level==1)
            {
                if(xball >=500-10 && xball<=500+16+10 && removed[0]==0)
                {
                    if(yball>=20-10 && yball<= 20+32+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.5;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[0]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=535-10 && xball<=535+16+10 && removed[1]==0)
                {
                    if(yball>=20-10 && yball<= 20+32+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.5;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[1]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=510-10 && xball<=510+32+10 && removed[2]==0)
                {
                    if(yball>=53-10 && yball<= 53+16+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.5;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[2]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=544-10 && xball<=544+65+10 && removed[3]==0)
                {
                    if(yball>=54-10 && yball<= 54+10+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.5;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[3]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=600-10 && xball<=600+16+10 && removed[4]==0)
                {
                    if(yball>=20-10 && yball<= 20+32+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.5;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[4]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=635-10 && xball<=635+16+10 && removed[5]==0)
                {
                    if(yball>=20-10 && yball<= 20+32+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.5;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[5]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=610-10 && xball<=610+32+10 && removed[6]==0)
                {
                    if(yball>=53-10 && yball<= 53+16+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.5;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[6]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=644-10 && xball<=644+65+10 && removed[7]==0)
                {
                    if(yball>=54-10 && yball<= 64+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.5;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[7]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=700-10 && xball<=700+16+10 && removed[8]==0)
                {
                    if(yball>=20-10 && yball<= 20+32+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.5;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[8]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=735-10 && xball<=735+16+10 && removed[9]==0)
                {
                    if(yball>=20-10 && yball<= 20+32+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.5;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[9]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=710-10 && xball<=710+32+10 && removed[10]==0)
                {
                    if(yball>=53-10 && yball<= 53+16+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.5;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[10]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=544-10 && xball<=544+10+10 && removed[11]==0)
                {
                    if(yball>=65-10 && yball<= 65+65+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.3;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[11]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=644-10 && xball<=644+10+10 && removed[12]==0)
                {
                    if(yball>=65-10 && yball<= 65+65+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.3;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[12]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=597-10 && xball<=597+10+10 && removed[13]==0)
                {
                    if(yball>=65-10 && yball<= 65+65+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.3;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[13]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=697-10 && xball<=697+10+10 && removed[14]==0)
                {
                    if(yball>=65-10 && yball<= 65+65+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.3;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[14]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=543-10 && xball<=543+65+10 && removed[15]==0)
                {
                    if(yball>=130-10 && yball<= 130+10+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.3;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[15]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=643-10 && xball<=643+65+10 && removed[16]==0)
                {
                    if(yball>=130-10 && yball<= 130+10+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.3;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[16]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=594-10 && xball<=594+70+10 && removed[17]==0)
                {
                    if(yball>=139-10 && yball<= 139+10+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.1;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[17]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=558-10 && xball<=558+36+10 && removed[18]==0)
                {
                    if(yball>=139-10 && yball<= 139+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.1;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[18]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=558-10 && xball<=558+36+10 && removed[19]==0)
                {
                    if(yball>=155-10 && yball<= 155+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.1;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[19]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=558-10 && xball<=558+36+10 && removed[20]==0)
                {
                    if(yball>=171-10 && yball<= 171+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.1;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[20]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=558-10 && xball<=558+36+10 && removed[21]==0)
                {
                    if(yball>=187-10 && yball<= 187+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.1;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[21]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=663-10 && xball<=663+36+10 && removed[22]==0)
                {
                    if(yball>=139-10 && yball<= 139+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.1;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[22]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=663-10 && xball<=663+36+10 && removed[23]==0)
                {
                    if(yball>=155-10 && yball<= 155+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.1;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[23]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=663-10 && xball<=663+36+10 && removed[24]==0)
                {
                    if(yball>=171-10 && yball<= 171+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.1;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[24]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=663-10 && xball<=663+36+10 && removed[25]==0)
                {
                    if(yball>=187-10 && yball<= 187+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.1;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[25]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=558-10 && xball<=628+70+10 && removed[26]==0)
                {
                    if(yball>=207-10 && yball<= 207+10+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.1;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[26]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=800-10 && xball<=800+20+10 && removed[27]==0)
                {
                    if(yball>=18-10 && yball<= 18+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.3;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[27]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=850-10 && xball<=850+20+10 && removed[28]==0)
                {
                    if(yball>=18-10 && yball<= 18+20+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.3;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[28]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=800-10 && xball<=800+65+10 && removed[29]==0)
                {
                    if(yball>=35-10 && yball<= 35+10+10 )
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.3;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[29]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if (yball<=35 && col!=3)
                {
                    col=3;
                    x=xball;
                    y=yball;
                    vx=vx;
                    vy=-(vy-g*(t-tcol))/2;
                    tcol=t;
                }
                if(col==3)
                {
                    if(yball>=35)
                        col=0;
                }
                if(xball >=605-10 && xball<=605+50+10)
                {
                    if(yball>=220-10 && yball<=220+45+10 )
                    {
                        if(gem1==0)
                        {
                            gem1=1;
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                        }
                    }

                    if (gem1!=1)
                        gem1=0;
                }
                if(xball >=610-10 && xball<=650+10 )
                {
                    if(yball>=149-10 && yball<=149+40+10)
                    {
                        if(gem2==0)
                        {
                            gem2=1;
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                        }
                    }
                    if (gem2!=1)
                        gem2=0;
                }
                if(xball >=555-15 && xball<=555+40+10 )
                {
                    if(yball>=65-10 && yball<=65+40+10 )
                    {
                        if(gem3==0)
                        {
                            gem3=1;
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                        }
                    }
                    if (gem3!=1)
                        gem3=0;
                }
                if(xball >=655-10 && xball<=655+40+10)
                {
                    if(yball>=65-10 && yball<=65+40+10 )
                    {
                        if(gem4==0)
                        {
                            gem4=1;
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                        }
                    }
                    if (gem4!=1)
                        gem4=0;
                }
                if(xball >=800-10 && xball<=800+70+10)
                {
                    if(yball>=38-10 && yball<=38+65+10)
                    {
                        if(gem5==0)
                        {
                            gem5=1;
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                        }
                    }
                    if (gem5!=1)
                        gem5=0;
                }
                gem6=1;
            }
            if(level==2)
            {
                if(xball >=500-10 && xball<=500+16+10 && removed[0]==0)
                {
                    if(yball>=20-10 && yball<= 20+32+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[0]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=550-10 && xball<=550+16+10 && removed[1]==0)
                {
                    if(yball>=20-10 && yball<= 20+32+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[1]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=550-10 && xball<=550+65+10 && removed[2]==0)
                {
                    if(yball>=52-10 && yball<= 52+10+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[2]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=650-10 && xball<=650+16+10 && removed[3]==0)
                {
                    if(yball>=20-10 && yball<= 20+32+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[3]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=700-10 && xball<=700+16+10 && removed[4]==0)
                {
                    if(yball>=20-10 && yball<= 20+32+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[4]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=650-10 && xball<=650+65+10 && removed[5]==0)
                {
                    if(yball>=52-10 && yball<= 52+10+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[5]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=530-10 && xball<=530+10+10 && removed[6]==0)
                {
                    if(yball>=62-10 && yball<= 62+65+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[6]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=680-10 && xball<=680+10+10 && removed[7]==0)
                {
                    if(yball>=62-10 && yball<= 62+65+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[7]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=525-10 && xball<=525+32+10 && removed[8]==0)
                {
                    if(yball>=140-10 && yball<= 140+16+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.6;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[8]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=525-10 && xball<=525+32+10 && removed[9]==0)
                {
                    if(yball>=156-10 && yball<= 156+16+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.6;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[9]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=525-10 && xball<=525+32+10 && removed[10]==0)
                {
                    if(yball>=172-10 && yball<= 172+16+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.6;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[10]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=525-10 && xball<=525+32+10 && removed[11]==0)
                {
                    if(yball>=188-10 && yball<= 188+16+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.6;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[11]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=675-10 && xball<=675+32+10 && removed[12]==0)
                {
                    if(yball>=140-10 && yball<= 140+16+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.6;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[12]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=675-10 && xball<=675+32+10 && removed[13]==0)
                {
                    if(yball>=156-10 && yball<= 156+16+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.6;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[13]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=675-10 && xball<=675+32+10 && removed[14]==0)
                {
                    if(yball>=172-10 && yball<= 172+16+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.6;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[14]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=675-10 && xball<=675+32+10 && removed[15]==0)
                {
                    if(yball>=188-10 && yball<= 188+16+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.6;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[15]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=550-10 && xball<=550+65+10 && removed[16]==0)
                {
                    if(yball>=204-10 && yball<= 204+10+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.6;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[16]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=615-10 && xball<=615+65+10 && removed[17]==0)
                {
                    if(yball>=204-10 && yball<= 204+10+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.6;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[17]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if (xball>=510-10 && xball <=500+221+10 && col!=3)
                {
                    if (yball >=128-10 && yball <=128+15+10)
                    {
                        col=3;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=-(vy-g*(t-tcol))/2;
                        tcol=t;
                    }
                }
                if (yball<=20+15 && col!=3)
                {
                    col=3;
                    x=xball;
                    y=yball;
                    vx=vx/1.2;
                    vy=-(vy-g*(t-tcol))/2;
                    tcol=t;
                }
                if (xball>=500-10 && xball <=500+10 && col!=4)
                {
                    if (yball >=128-10 && yball <=128+15+10)
                    {
                        col=4;
                        x=xball;
                        y=yball;
                        vx=-vx/4;
                        vy=-(vy-g*(t-tcol))/4;
                        tcol=t;

                    }
                }
                if(col==3)
                {
                    if(xball<=510-10 || xball>=510+221+10 || yball<128-10 || yball>128+15+10)
                    {
                        if(yball>=35)
                            col=0;
                    }
                }
                if(xball >=590-10 && xball<=590+50+10)
                {
                    if(yball>=142-10 && yball<=142+50+10)
                    {
                        if(gem1==0)
                        {
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                            gem1=1;
                        }

                    }

                    if (gem1!=1)
                        gem1=0;
                }
                if(xball >=585-10 && xball<=585+50+10)
                {
                    if(yball>=25-10 && yball<=45+45+10)
                    {
                        if(gem2==0)
                        {
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                            gem2=1;
                        }

                    }

                    if (gem2!=1)
                        gem2=0;
                }
                if(xball >=670-10 && xball<=670+25+10)
                {
                    if(yball>=20-10 && yball<=20+25+10)
                    {
                        if(gem3==0)
                        {
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                            gem3=1;
                        }

                    }

                    if (gem3!=1)
                        gem3=0;
                }
                if(xball >=520-10 && xball<=520+25+10)
                {
                    if(yball>=20-10 && yball<=20+25+10)
                    {
                        if(gem4==0)
                        {
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                            gem4=1;
                        }

                    }

                    if (gem4!=1)
                        gem4=0;
                }
                gem5=1;
                gem6=1;
            }

            if(level==3)
            {
                if(xball >=500-10 && xball<=500+65+10 && removed[0]==0)
                {
                    if(yball>=76-10 && yball<= 76+10+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.6;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[0]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=500-10 && xball<=500+10+10 && removed[1]==0)
                {
                    if(yball>=20-10 && yball<= 20+65+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.6;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[1]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=565-10 && xball<=565+36+10 && removed[2]==0)
                {
                    if(yball>=85-10 && yball<= 85+20+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[2]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=565-10 && xball<=565+36+10 && removed[3]==0)
                {
                    if(yball>=101-10 && yball<= 101+20+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[3]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=565-10 && xball<=565+36+10 && removed[4]==0)
                {
                    if(yball>=117-10 && yball<= 117+20+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[4]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=565-10 && xball<=565+70+10 && removed[5]==0)
                {
                    if(yball>=133-10 && yball<= 133+10+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[5]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=734-10 && xball<=734+36+10 && removed[6]==0)
                {
                    if(yball>=85-10 && yball<= 85+20+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[6]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=734-10 && xball<=734+36+10 && removed[7]==0)
                {
                    if(yball>=101-10 && yball<= 101+20+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[7]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=734-10 && xball<=734+36+10 && removed[8]==0)
                {
                    if(yball>=117-10 && yball<= 117+20+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[8]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=700-10 && xball<=700+70+10 && removed[9]==0)
                {
                    if(yball>=133-10 && yball<= 133+10+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.2;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[9]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=770-10 && xball<=770+65+10 && removed[10]==0)
                {
                    if(yball>=76-10 && yball<= 76+10+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.6;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[10]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=826-10 && xball<=826+10+10 && removed[11]==0)
                {
                    if(yball>=20-10 && yball<= 20+65+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.6;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[11]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball >=690-10 && xball<=690+10+10 && removed[12]==0)
                {
                    if(yball>=20-10 && yball<= 20+65+10)
                    {
                        col=2;
                        x=xball;
                        y=yball;
                        vx=vx/1.6;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                        removed[12]=1;
                        scr=scr+100;
                        itoa(scr,showscor,10);
                    }
                }
                if(xball>=620 && xball<=630 && col!=1)
                {
                    if (yball>=143-10 &&yball<=143+10+55)
                    {
                            col=1;
                            x=xball;
                            y=yball;
                            vx=-vx/4;
                            vy=vy-g*(t-tcol);
                            tcol=t;
                    }
                }
                if (xball>=645-10 && xball <=635+65+10 && col!=3)
                {
                    if (yball >=198-10 && yball <=198+10+10)
                    {
                        col=3;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=-(vy-g*(t-tcol))/2;
                        tcol=t;
                    }
                }
                if (xball>=635-10 && xball <=635 && col!=4)
                {
                    if (yball >=198-10 && yball <=198+10+10)
                    {
                        col=4;
                        x=xball;
                        y=yball;
                        vx=-vx/4;
                        vy=-(vy-g*(t-tcol))/4;
                        tcol=t;

                    }
                }
                if (xball>=575-10 && xball <=565+65+10 && col!=3)
                {
                    if (yball >=76-10 && yball <=76+10+10)
                    {
                        col=3;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=-(vy-g*(t-tcol))/2;
                        tcol=t;
                    }
                }
                if (xball>=565-10 && xball <=565 && col!=4)
                {
                    if (yball >=76-10 && yball <=76+10+10)
                    {
                        col=4;
                        x=xball;
                        y=yball;
                        vx=-vx/4;
                        vy=-(vy-g*(t-tcol))/4;
                        tcol=t;

                    }
                }
                if (xball>=715-10 && xball <=700+70+10 && col!=3)
                {
                    if (yball >=76-10 && yball <=76+10+10)
                    {
                        col=3;
                        x=xball;
                        y=yball;
                        vx=vx/2;
                        vy=-(vy-g*(t-tcol))/2;
                        tcol=t;
                    }
                }
                if (xball>=700-10 && xball <=705 && col!=4)
                {
                    if (yball >=76-10 && yball <=76+10+10)
                    {
                        col=4;
                        x=xball;
                        y=yball;
                        vx=-vx/4;
                        vy=-(vy-g*(t-tcol))/4;
                        tcol=t;

                    }
                }
                if (yball<=20+15 && col!=3)
                {
                    col=3;
                    x=xball;
                    y=yball;
                    vx=vx/1.2;
                    vy=-(vy-g*(t-tcol))/2;
                    tcol=t;
                }
                if(col==3)
                {
                    if(xball<=635-10 || xball >=635+65+10 || yball <=198-10 || yball >=198+10+10)
                    {
                        if(xball<=565-10 || xball >=565+65+10 || yball <=76-10 || yball >=76+10+10)
                        {
                            if(xball<=715-10 || xball >=700+70+10 || yball <=76-10 || yball >=76+10+10)
                            {
                                if(yball>=35)
                                    col=0;
                            }
                        }
                    }
                }
                if(col==4)
                {
                    if(xball<=635-10 || xball >=635 || yball <=198-10 || yball >=198+10+10)
                    {
                        if(xball<=565-10 || xball >=565 || yball <=76-10 || yball >=76+10+10)
                        {
                            if(xball<=690 || xball >=705 || yball <=76-10 || yball >=76+10+10)
                                col=0;
                        }
                    }
                }
                if(xball >=635-10 && xball<=635+70+10)
                {
                    if(yball>=200-10 && yball<=200+75+10)
                    {
                        if(gem1==0)
                        {
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                            gem1=1;
                        }

                    }

                    if (gem1!=1)
                        gem1=0;
                }
                if(xball >=570-10 && xball<=570+50+10)
                {
                    if(yball>=143-10 && yball<=143+45+10 )
                    {
                        if(gem2==0)
                        {
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                            gem2=1;
                        }
                    }
                    if (gem2!=1)
                        gem2=0;
                }
                if(xball >=715-10 && xball<=715+50+10)
                {
                    if(yball>=143-10 && yball<=143+45+10 )
                    {
                        if(gem3==0)
                        {
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                            gem3=1;
                        }
                    }
                    if (gem3!=1)
                        gem3=0;
                }
                if(xball >=605-10 && xball<=605+25+10)
                {
                    if(yball>=85-10 && yball<=85+25+10)
                    {
                        if(gem4==0)
                        {
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                            gem4=1;
                        }
                    }
                    if (gem4!=1)
                        gem4=0;
                }
                if(xball >=700-10 && xball<=700+25+10)
                {
                    if(yball>=85-10 && yball<=85+25+10)
                    {
                        if(gem5==0)
                        {
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                            gem5=1;
                        }
                    }
                    if (gem5!=1)
                        gem5=0;
                }
                if(xball >=700 && xball<=700+45+10)
                {
                    if(yball>=20-10 && yball<=40+10)
                    {
                        if(gem6==0)
                        {
                            scr=scr+1000;
                            itoa(scr,showscor,10);
                            gem6=1;
                        }
                    }
                    if (gem6!=1)
                        gem6=0;
                }
            }

        }
        else
        {
            t=tcol=0;
            check=0;
            running=0;
            mapping=col=0;
            direction=1;
            xball=75;
            yball=75;
            x=xball;
            y=yball;
            num++;
        }
        //the console 3 can be only operated by the console 2 as an input this if is done when game is over
        if(num==5 && (gem1==0 || gem2==0 || gem3==0 || gem4==0 || gem5==0 || gem6==0))
        {
            consol=3;
            consol2out=1;
            num=0;
            gem1=0;
            gem2=0;
            gem3=0;
            gem4=0;
            gem5=0;
            gem6=0;
            t=tcol=0;
            check=0;
            running=0;
            mapping=col=0;
            direction=1;
            x=xball=75;
            y=yball=75;
            for(int i=0;i<35;i++)
            {
                removed[i]=0;
            }
            if (musicon)
            {
                PlaySound(0,0,0);
                PlaySound("lion sleeps tonight.wav",NULL,SND_LOOP | SND_ASYNC);
            }
        }
        else if(gem1==1 && gem2==1 && gem3==1 && gem4==1 && gem5==1 && gem6==1)
        {
            scor[level]=scr;
            level++;
            num=0;
            gem1=0;
            gem2=0;
            gem3=0;
            gem4=0;
            gem5=0;
            gem6=0;
            consol=3;
            t=tcol=0;
            check=0;
            running=0;
            mapping=col=0;
            direction=1;
            x=xball=75;
            y=yball=75;
            consol2out=2;
            if (level==4)
            {

                level=0;
                consol=3;
                consol2out=3;
                for (int i=0;i<5;i++)
                {
                    if(scr>arr[i].score)
                    {
                        consol2out=4;
                        break;
                    }
                }
            }
            for(int i=0;i<35;i++)
            {
                removed[i]=0;
                //printf("removed [%d]=%d\n",i,removed[i]);
            }
            if (musicon)
            {
                PlaySound(0,0,0);
                PlaySound("dun dun duun.wav",NULL,SND_LOOP | SND_ASYNC);
            }
        }

    }

}

void backgrounddraw()
{
    backgnd++;
    char str[20],buf[5];
    if (dark==0)
    {
        strcpy(str,"back");
        backgnd=backgnd%1225;
        if(backgnd<48)
            backgnd=48;
    }
    else
    {
        strcpy(str,"dback");
        backgnd=backgnd%282;
    }
    if(backgnd<10)
        strcat(str,"000");
    else if (backgnd<100)
        strcat(str,"00");
    else if (backgnd<1000)
        strcat(str,"0");
    itoa(backgnd,buf,10);
    strcat(str,buf);
    strcat(str,".bmp");
    iShowBMP(0,0,str);
}
void iDraw()
{
    //place your drawing codes here
    iClear();
    if(consol==0)
    {

        iShowBMP(0,0,"angry bird start.bmp");
        iShowBMP2(350,50,"ibirds logo.bmp",0);
        iText(450,30,"Loading",GLUT_BITMAP_TIMES_ROMAN_24);
        if(startdot==0)
        {
            iFilledRectangle(533,24,4,4);
        }
        if(startdot==1)
        {
            iFilledRectangle(533,24,4,4);
            iFilledRectangle(539,24,4,4);
        }
        if(startdot==2)
        {
            iFilledRectangle(533,24,4,4);
            iFilledRectangle(539,24,4,4);
            iFilledRectangle(545,24,4,4);
        }
        if(startdot==3)
        {
            iFilledRectangle(533,24,4,4);
            iFilledRectangle(539,24,4,4);
            iFilledRectangle(545,24,4,4);
            iFilledRectangle(551,24,4,4);
        }
        iFilledRectangle(0,15,startx,5);
    }
    if(consol == 1)
    {
        backgrounddraw();
        iSetColor(255,255,0);
        iEllipse(500,20+20,100,20);
        iEllipse(500,60+20,100,20);
        iEllipse(500,100+20,106,22);
        iEllipse(500,140+20,100,20);
        iEllipse(500,180+20,100,20);
        iEllipse(500,220+20,100,20);
        iEllipse(500,260+20,100,20);
        iSetColor(255,255,255);
        iText(475,31,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(461,71,"ABOUT",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(408,111,"HALL OF FAMES",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(445,151,"SETTINGS",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(465,191,"HELPS",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(440,231,"NEW GAME",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(440,271,"CONTINUE",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if (consol==2)
    {
        //user presses continue the problem has been solved !!!!!!!!!!
        //uesr presses new game
        if(consolout==2)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"background.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird dark mode background.bmp");
            }
            iShowBMP2(55,20,"shooter.bmp",0);
            iShowBMP2(55-35,420,"backicon.bmp",0);
            iSetColor(255,0,0);
            //for power indicator
            iRectangle(10,20,8,101);
            iFilledRectangle(11,21,6,mapping);
            iSetColor(0,0,0);
            iLine(75,75,xshow+75,yshow+75);
            iShowBMP2(800,392,"scoreboard.bmp",0);
            iText(820,392,showscor,GLUT_BITMAP_TIMES_ROMAN_24);
            //iLine(100,240,800,240);
            iSetColor(0,0,255);
            iShowBMP2(xball-15,yball-15,"bird.bmp",0);
            if(level==0)
            {
                iShowBMP2(558,120,"non removable obstacle.bmp",0);
                if(removed[0]==0)
                    iShowBMP2(560,20,"wood3.bmp",0);//0
                if(removed[1]==0)
                    iShowBMP2(610,20,"wood4.bmp",0);//1
                if(removed[2]==0)
                    iShowBMP2(560,35,"rock2.bmp",0);//2
                if(removed[3]==0)
                    iShowBMP2(580,45,"rock3.bmp",0);//3
                if(removed[4]==0)
                    iShowBMP2(579,77,"wood4.bmp",0);//4
                if(removed[5]==0)
                    iShowBMP2(710,20,"wood3.bmp",0);//5
                if(removed[6]==0)
                    iShowBMP2(760,20,"wood4.bmp",0);//6
                if(removed[7]==0)
                    iShowBMP2(710,35,"rock2.bmp",0);//7
                if(removed[8]==0)
                    iShowBMP2(730,45,"rock3.bmp",0);//8
                if(removed[9]==0)
                    iShowBMP2(729,77,"wood4.bmp",0);//9
                if(removed[10]==0)
                    iShowBMP2(560,132,"ice4.bmp",0);//10
                if(removed[11]==0)
                    iShowBMP2(560,148,"ice4.bmp",0);//11
                if(removed[12]==0)
                    iShowBMP2(560,164,"ice4.bmp",0);//12
                if(removed[13]==0)
                    iShowBMP2(560,180,"ice4.bmp",0);//13
                if(removed[14]==0)
                    iShowBMP2(652,132,"ice4.bmp",0);//14
                if(removed[15]==0)
                    iShowBMP2(652,148,"ice4.bmp",0);//15
                if(removed[16]==0)
                    iShowBMP2(652,164,"ice4.bmp",0);//16
                if(removed[17]==0)
                    iShowBMP2(652,180,"ice4.bmp",0);//17
                if(removed[18]==0)
                    iShowBMP2(590,200,"ice1.bmp",0);//18
                if(removed[19]==0)
                    iShowBMP2(744,132,"ice4.bmp",0);//19
                if(removed[20]==0)
                    iShowBMP2(744,148,"ice4.bmp",0);//20
                if(removed[21]==0)
                    iShowBMP2(744,164,"ice4.bmp",0);//21
                if(removed[22]==0)
                    iShowBMP2(744,180,"ice4.bmp",0);//22
                if(removed[23]==0)
                    iShowBMP2(682,200,"ice1.bmp",0);//23
                if(gem1==0)
                {
                    iShowBMP2(750,45,"npigs1.bmp",0);
                }
                if(gem2==0)
                {
                    iShowBMP2(600,45,"npigs1.bmp",0);
                }
                if(gem3==0)
                {
                    iShowBMP2(695,134,"hpig.bmp",0);
                }
                if(gem4==0)
                {
                    iShowBMP2(600,134,"hpig.bmp",0);
                }
            }
            else if(level==1)
            {
                if(removed[0]==0)
                    iShowBMP2(500,20,"rock3.bmp",0);//0
                if(removed[1]==0)
                    iShowBMP2(535,20,"rock3.bmp",0);//1
                if(removed[2]==0)
                    iShowBMP2(510,53,"rock4.bmp",0);//2
                if(removed[3]==0)
                    iShowBMP2(544,54,"rock2.bmp",0);//3
                if(removed[4]==0)
                    iShowBMP2(600,20,"rock3.bmp",0);//4
                if(removed[5]==0)
                    iShowBMP2(635,20,"rock3.bmp",0);//5
                if(removed[6]==0)
                    iShowBMP2(610,53,"rock4.bmp",0);//6
                if(removed[7]==0)
                    iShowBMP2(644,54,"rock2.bmp",0);//7
                if(removed[8]==0)
                    iShowBMP2(700,20,"rock3.bmp",0);//8
                if(removed[9]==0)
                    iShowBMP2(735,20,"rock3.bmp",0);//9
                if(removed[10]==0)
                    iShowBMP2(710,53,"rock4.bmp",0);//10
                if(removed[11]==0)
                    iShowBMP2(544,65,"wood2.bmp",0);//11
                if(removed[12]==0)
                    iShowBMP2(644,65,"wood2.bmp",0);//12
                if(removed[13]==0)
                    iShowBMP2(597,65,"wood2.bmp",0);//13
                if(removed[14]==0)
                    iShowBMP2(697,65,"wood2.bmp",0);//14
                if(removed[15]==0)
                    iShowBMP2(543,130,"wood1.bmp",0);//15
                if(removed[16]==0)
                    iShowBMP2(643,130,"wood1.bmp",0);//16
                if(removed[17]==0)
                    iShowBMP2(594,139,"ice1.bmp",0);//17
                if(removed[18]==0)
                    iShowBMP2(558,139,"ice4.bmp",0);//18
                if(removed[19]==0)
                    iShowBMP2(558,155,"ice4.bmp",0);//19
                if(removed[20]==0)
                    iShowBMP2(558,171,"ice4.bmp",0);//20
                if(removed[21]==0)
                    iShowBMP2(558,187,"ice4.bmp",0);//21
                if(removed[22]==0)
                    iShowBMP2(663,139,"ice4.bmp",0);//22
                if(removed[23]==0)
                    iShowBMP2(663,155,"ice4.bmp",0);//23
                if(removed[24]==0)
                    iShowBMP2(663,171,"ice4.bmp",0);//24
                if(removed[25]==0)
                    iShowBMP2(663,187,"ice4.bmp",0);//25
                if(removed[26]==0)
                    iShowBMP2(558,207,"ice1.bmp",0);//26
                if(removed[26]==0)
                    iShowBMP2(628,207,"ice1.bmp",0);//26
                if(removed[27]==0)//printf("ami gadha!!!!!!!!!");
                    iShowBMP2(800,18,"wood4.bmp",0);//27
                if(removed[28]==0)
                    iShowBMP2(850,18,"wood4.bmp",0);//28
                if(removed[29]==0)
                    iShowBMP2(800,35,"wood1.bmp",0);//29
                if(gem1==0)
                {
                    iShowBMP2(605,220,"hpig.bmp",0);
                }
                if(gem2==0)
                {
                    iShowBMP2(610,149,"npigs2.bmp",0);
                }
                if(gem3==0)
                {
                    iShowBMP2(555,65,"npigs2.bmp",0);
                }
                if(gem4==0)
                {
                    iShowBMP2(655,65,"npigs2.bmp",0);
                }
                if(gem5==0)
                {
                    iShowBMP2(800,38,"mpig.bmp",0);
                }
            }
            else if(level==2)
            {
                if(removed[0]==0)
                    iShowBMP2(500,20,"rock3.bmp",0);//0
                if(removed[1]==0)
                    iShowBMP2(550,20,"rock3.bmp",0);//1
                if(removed[2]==0)
                    iShowBMP2(500,52,"rock2.bmp",0);//2
                if(removed[3]==0)
                    iShowBMP2(650,20,"rock3.bmp",0);//3
                if(removed[4]==0)
                    iShowBMP2(700,20,"rock3.bmp",0);//4
                if(removed[5]==0)
                    iShowBMP2(650,52,"rock2.bmp",0);//5
                if(removed[6]==0)
                    iShowBMP2(530,62,"rock1.bmp",0);//6
                if(removed[7]==0)
                    iShowBMP2(680,62,"rock1.bmp",0);//7
                if(removed[8]==0)
                    iShowBMP2(525,140,"wood3.bmp",0);//8
                if(removed[9]==0)
                    iShowBMP2(525,156,"wood3.bmp",0);//9
                if(removed[10]==0)
                    iShowBMP2(525,172,"wood3.bmp",0);//10
                if(removed[11]==0)
                    iShowBMP2(525,188,"wood3.bmp",0);//11
                if(removed[12]==0)
                    iShowBMP2(675,140,"wood3.bmp",0);//12
                if(removed[13]==0)
                    iShowBMP2(675,156,"wood3.bmp",0);//13
                if(removed[14]==0)
                    iShowBMP2(675,172,"wood3.bmp",0);//14
                if(removed[15]==0)
                    iShowBMP2(675,188,"wood3.bmp",0);//15
                if(removed[16]==0)
                    iShowBMP2(550,204,"wood1.bmp",0);//16
                if(removed[17]==0)
                    iShowBMP2(615,204,"wood1.bmp",0);//17
                iShowBMP2(500,128,"non removable obstacle.bmp",0);
                if(gem1==0)
                {
                    iShowBMP2(590,142,"npigs3.bmp",0);
                }
                if(gem2==0)
                {
                    iShowBMP2(585,25,"hpig.bmp",0);
                }
                if(gem3==0)
                {
                    iShowBMP2(670,20,"npigs1.bmp",0);
                }
                if(gem4==0)
                {
                    iShowBMP2(520,20,"npigs1.bmp",0);
                }

            }
            else if(level==3)
            {
                iFilledRectangle(635,198,65,9);
                iFilledRectangle(635,143,9,55);
                iFilledRectangle(565,76,65,9);
                iFilledRectangle(700,76,70,9);
                if(removed[0]==0)
                    iShowBMP2(500,76,"wood1.bmp",0);//0
                if(removed[1]==0)
                    iShowBMP2(500,20,"wood2.bmp",0);//1
                if(removed[2]==0)
                    iShowBMP2(565,85,"ice4.bmp",0);//2
                if(removed[3]==0)
                    iShowBMP2(565,101,"ice4.bmp",0);//3
                if(removed[4]==0)
                    iShowBMP2(565,117,"ice4.bmp",0);//4
                if(removed[5]==0)
                    iShowBMP2(565,133,"ice1.bmp",0);//5
                if(removed[6]==0)
                    iShowBMP2(734,85,"ice4.bmp",0);//6
                if(removed[7]==0)
                    iShowBMP2(734,101,"ice4.bmp",0);//7
                if(removed[8]==0)
                    iShowBMP2(734,117,"ice4.bmp",0);//8
                if(removed[9]==0)
                    iShowBMP2(700,133,"ice1.bmp",0);//9
                if(removed[10]==0)
                    iShowBMP2(770,76,"wood1.bmp",0);//10
                if(removed[11]==0)
                    iShowBMP2(826,20,"wood2.bmp",0);//11
                if(removed[12]==0)
                    iShowBMP2(690,20,"wood2.bmp",0);//12
                if(gem1==0)
                {
                    iShowBMP2(635,200,"kpig.bmp",0);
                }
                if(gem2==0)
                {
                    iShowBMP2(570,143,"hpig.bmp",0);
                }
                if(gem3==0)
                {
                    iShowBMP2(715,143,"hpig.bmp",0);
                }
                if(gem4==0)
                {
                    iShowBMP2(605,85,"npigs1.bmp",0);
                }
                if(gem5==0)
                {
                    iShowBMP2(700,85,"npigs1.bmp",0);
                }
                if(gem6==0)
                {
                    iShowBMP2(710,20,"egg.bmp",0);
                }
            }

        }
        //helps
        if (consolout==3)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"angry bird consol 1.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird consol 1 dark mode.bmp");
            }
            iShowBMP2(0,0,"help.bmp",0);
            iShowBMP2(55-35,420,"backicon.bmp",0);
            //iShowBMP2(24,442,"back.bmp",0);
        }
        //settings
        if (consolout==4)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"angry bird consol 1.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird consol 1 dark mode.bmp");
                iSetColor(255,255,255);
                iShowBMP2(450,20,"tick sign.bmp",255);
            }
            if (musicon==true)
                iShowBMP2(450,60,"tick sign.bmp",255);
            iRectangle(200,20,200,35);
            iRectangle(200,60,200,35);
            iRectangle(450,20,35,35);
            iRectangle(450,60,35,35);
            iText(200,71,"MUSIC",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(200,111,"RECOMMEND",GLUT_BITMAP_TIMES_ROMAN_24);
            //iRectangle(500,100,200,35);
            iShowBMP2(24,442,"back.bmp",0);


        }
        //high score
        if (consolout==5)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"angry bird consol 1.bmp");
                iSetColor(0,0,0);
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird consol 1 dark mode.bmp");
                iSetColor(255,255,255);
            }
            iRectangle(200,20,200,35);
            iRectangle(200,60,200,35);
            iRectangle(200,100,200,35);
            iRectangle(200,140,200,35);
            iRectangle(200,180,200,35);
            iRectangle(500,20,100,35);
            iRectangle(500,60,100,35);
            iRectangle(500,100,100,35);
            iRectangle(500,140,100,35);
            iRectangle(500,180,100,35);
            iShowBMP2(24,442,"back.bmp",0);
            char buf[10];
            itoa(arr[0].score,buf,10);
            iText(505,191,buf,GLUT_BITMAP_TIMES_ROMAN_24);
            itoa(arr[1].score,buf,10);
            iText(505,151,buf,GLUT_BITMAP_TIMES_ROMAN_24);
            itoa(arr[2].score,buf,10);
            iText(505,111,buf,GLUT_BITMAP_TIMES_ROMAN_24);
            itoa(arr[3].score,buf,10);
            iText(505,71,buf,GLUT_BITMAP_TIMES_ROMAN_24);
            itoa(arr[4].score,buf,10);
            iText(505,31,buf,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(205,31,arr[4].name,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(205,71,arr[3].name,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(205,111,arr[2].name,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(205,151,arr[1].name,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(205,191,arr[0].name,GLUT_BITMAP_TIMES_ROMAN_24);

        }
        //about
        if (consolout==6)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"angry bird consol 1.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird consol 1 dark mode.bmp");
            }
            iSetColor(255,255,255);
            iShowBMP(0,0,"about.bmp");
            iShowBMP2(24,442,"back.bmp",0);

        }
        //presses exit
    }
    if(consol==3)
    {
        if(consol2out==0)//presses back
        {
                        if(dark ==0)
            {
                iShowBMP(0,0,"background.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird dark mode background.bmp");
            }
        iSetColor(0,0,0);
        iShowBMP2(250,50,"consol 3 sure.bmp",0);
        iText(360,200,"Are you sure you want to quit?",GLUT_BITMAP_HELVETICA_18);
        }

        if(consol2out==1)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"background.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird dark mode background.bmp");
            }
            iSetColor(0,0,255);
            iFilledEllipse(500,250,100,25,1000);
            iSetColor(255,255,255);
            iText(422,240,"GAME OVER!!",GLUT_BITMAP_TIMES_ROMAN_24);
            iShowBMP2(350-35,180-35,"backcir.bmp",0);
            iShowBMP2(500-35,180-35,"retry.bmp",0);
            iShowBMP2(650-35,180-35,"forward.bmp",0);
            iShowBMP2(650-35,180-35,"off.bmp",0);
            iSetColor(0,0,0);
            iText(415,100,"Your Score:",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(525,100,showscor,GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(consol2out==2)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"background.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird dark mode background.bmp");
            }
            iSetColor(0,0,255);
            iFilledEllipse(500,250,100,25,1000);
            iShowBMP2(350-35,180-35,"backcir.bmp",0);
            iShowBMP2(500-35,180-35,"retry.bmp",0);
            iShowBMP2(650-35,180-35,"forward.bmp",0);
            iSetColor(255,255,255);
            iText(420,240,"Congratulations!!",GLUT_BITMAP_TIMES_ROMAN_24);
            iSetColor(0,0,0);
            iText(415,100,"Your Score:",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(525,100,showscor,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if(consol2out==3)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"background.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird dark mode background.bmp");
            }
            iSetColor(0,0,255);
            iFilledEllipse(500,250,100,25,1000);
            iSetColor(255,255,255);
            iText(420,240,"Congratulations!!",GLUT_BITMAP_TIMES_ROMAN_24);
            iShowBMP2(350-35,180-35,"backcir.bmp",0);
            iShowBMP2(500-35,180-35,"retry.bmp",0);
            iShowBMP2(650-35,180-35,"forward.bmp",0);
            iShowBMP2(650-35,180-35,"off.bmp",0);
            iSetColor(0,0,0);
            iText(415,100,"Your Score:",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(525,100,showscor,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if (consol2out==4)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"background.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird dark mode background.bmp");
            }
            iSetColor(0,0,0);
            iShowBMP2(250,50,"consol 3 sure.bmp",0);
            iText(360,220,"Congratulations! High score!",GLUT_BITMAP_HELVETICA_18);
            iText(310,180,"Click on this consol once and then put your name in the black consol",GLUT_BITMAP_HELVETICA_12);
        }

    }
    if(consol==4)
    {
        if(dark ==0)
        {
            iShowBMP(0,0,"background.bmp");
        }
        else if (dark ==1)
        {
            iShowBMP(0,0,"angry bird dark mode background.bmp");
        }
        iSetColor(0,0,0);
        iShowBMP2(250,110,"consol 3 sure.bmp",0);
        iText(360,270,"Do you want to save the progress?",GLUT_BITMAP_HELVETICA_18);
    }

}
void iMouseMove(int mx, int my)
{
//place your codes here
}
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(consol == 1)
        {
            if(mx>=395 && mx<=605 && my>=260 && my<=295)
            {
                FILE *fp=fopen("continue.txt","r");
                if(fp==NULL)
                {
                    printf("error");
                    exit(1);
                }
                fscanf(fp,"%d %d %d",&level,&num,&scr);
                fscanf(fp,"%d %d %d %d %d",&gem1,&gem2,&gem3,&gem4,&gem5);
                for(int i=0;i<35;i++)
                {
                    fscanf(fp,"%d",&removed[i]);
                }
                fclose(fp);
                check =0;
                t=tcol=0;
                consol++;
                consolout=2;
            }
            if(mx>=395 && mx<=605 && my>=220 && my<=255)
            {
                consol++;
                consolout=2;
                level=0;
                ang=0;
                angle=0;
                xshow=100*cos(angle);
                yshow=100*sin(angle);
                num=0;
                gem1=gem2=gem3=gem4=gem5=gem6=0;
                for (int i=0;i<35;i++)
                {
                    removed[i]=0;
                }
                scr=0;
            }

            if(mx>=395 && mx<=605 && my>=180 && my<=215)
            {
                consol++;
                consolout=3;
            }

            if(mx>=395 && mx<=605 && my>=140 && my<=175)
            {
                consol++;
                consolout=4;
            }

            if(mx>=395 && mx<=605 && my>=100 && my<=135)
            {
                consol++;
                consolout=5;
            }

            if(mx>=395 && mx<=605 && my>=60 && my<=95)
            {
                consol++;
                consolout=6;
            }
            if(mx>=395 && mx<=605 && my>=20 && my<=55)
            {
                exit(0);
            }
        }
        if (consol == 2)
        {
            if (consolout==2)
            {
                if(mx>=55-35 && mx<=55+35 && my>=450-35 && my<=450+35)
                {
                    consol++;
                    consol2out=0;
                    iPauseTimer(0);
                }
            }
            if (consolout==3)
            {
                if(mx>=55-35 && mx<=55+35 && my>=450-35 && my<=450+35)
                {
                    consol--;
                    consolout=0;
                }
            }

            if (consolout==4)
            {
                if(mx>=55-35 && mx<=55+35 && my>=450-35 && my<=450+35)
                {
                    consol--;
                    consolout=0;
                }

                if(mx>450 && mx<485 && my>20 && my<55)
                {
                    if(dark== 0)
                    {
                        dark=1;
                    }
                    else if (dark == 1)
                    {
                        dark =0;
                    }
                }
                if(mx>450 && mx<485 && my>60 && my<60+35)
                {
                    if(musicon==false)
                    {
                        musicon=true;
                        menumusic();
                    }
                    else if (musicon)
                    {
                        musicon=false;
                        PlaySound(0,0,0);
                    }
                }
            }

            if (consolout==5)
            {
                if(mx>=55-35 && mx<=55+35 && my>=450-35 && my<=450+35)
                {
                    consol--;
                    consolout=0;
                }
            }

            if (consolout==6)
            {
                if(mx>=55-35 && mx<=55+35 && my>=450-35 && my<=450+35)
                {
                    consol--;
                    consolout=0;
                }
            }
        }

        if(consol==3)
        {
            if(consol2out==0)//are you sure????
            {
                if(mx>=285 && mx<=355 && my>=120 && my<=182)//no
                {
                    consol=2;
                    consolout=2;
                    iResumeTimer(0);
                }
                if(mx>=595 && mx<=665 && my>=120 && my<=182)//yes
                {
                    consol++;
                }
//                printf("%d %d \n",mx,my);
            }
            if(consol2out==1)//game over
            {
                if(mx>=315 && mx<=385 && my >=145 && my<=215)//back
                {
                    consol++;
                    consol2out=0;
                    PlaySound(0,0,0);
                }
                if(mx>=460 && mx<=535 && my>145 && my<=215)//retry
                {
                    consol=2;
                    consolout=2;
                    ang=0;
                    angle=0;
                    xshow=100*cos(angle);
                    yshow=100*sin(angle);
                    scr=0;
                    PlaySound(0,0,0);
                }
                //printf("%d %d\n",mx,my);
            }
            if(consol2out==2)//level clear
            {
                if(mx>=315 && mx<=385 && my >=145 && my<=215)//back
                {
                    consol++;
                    consol2out=0;
                    PlaySound(0,0,0);
                }
                if(mx>=610 && mx<=685 && my>145 && my<=215)//forward
                {
                    consol=2;
                    consolout=2;
                    ang=0;
                    angle=0;
                    xshow=100*cos(angle);
                    yshow=100*sin(angle);
                    PlaySound(0,0,0);

                }
                if(mx>=460 && mx<=535 && my>145 && my<=215)//replay
                {
                    consol=2;
                    consolout=2;
                    level--;
                    ang=0;
                    angle=0;
                    xshow=100*cos(angle);
                    yshow=100*sin(angle);
                    scr=0;
                    PlaySound(0,0,0);
                }
                //printf("%d %d\n",mx,my);
            }
            if(consol2out==3)//last level clear
            {
                if(mx>=300 && mx<=400 && my >=160 && my<=200)//back
                {
                    consol++;
                    consol2out=0;
                    PlaySound(0,0,0);
                }
                if(mx>=600 && mx<=700 && my>160 && my<=200)//play again
                {
                    consol=2;
                    consolout=2;
                    ang=0;
                    angle=0;
                    xshow=100*cos(angle);
                    yshow=100*sin(angle);
                    PlaySound(0,0,0);

                }
            }
            if(consol2out==4)
            {
                highscore();
            }
        }
        if(consol==4)//do you want to save the game ?
        {
            if(mx>=280 && mx<=355 && my>=183 && my<=250)// no
            {
                consol=1;
                consolout=0;
                iResumeTimer(0);
                t=0;
                check=0;
                mapping=col=0;
                direction=1;
                xball=yball=75;
            }
            if(mx>=595 && mx<=665 && my>=183 && my<=250)// yes
            {
                FILE *fp=fopen("continue.txt","w");
                fprintf(fp,"%d %d %d\n",level,num,scr);
                fprintf(fp,"%d %d %d %d %d\n",gem1,gem2,gem3,gem4,gem5);
                for(int i=0;i<35;i++)
                {
                    fprintf(fp,"%d\n",removed[i]);
                }
                fclose(fp);
                consol=1;
                consolout=0;
                iResumeTimer(0);
                t=0;
                check=0;
                mapping=col=0;
                direction=1;
                xball=yball=75;
            }
//            printf("%d %d \n",mx,my);
        }
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
//place your codes here
    }

}
void iKeyboard(unsigned char key)
{
    if(key == ' ')
    {
        if (consol==2 && consolout==2)
        {
            if (check==0 || check == 1)
            check ++;
        }
    }
    if(check == 0 || check ==2)
    {
        iPauseTimer(1);
    }
    if(check ==1 )
    {
        iResumeTimer(1);
        if(musicon)
        {
            PlaySound(0,0,0);
            PlaySound("media.io_melodyloops-preview-happy-place-2m30s.wav",NULL,SND_LOOP | SND_ASYNC);
        }
    }
    if (check == 2 && running==0)
    {
        v=mapping;
        vx=vxi=v*cos(angle);
        vy=vyi=v*sin(angle);
        tmax=5*vyi/g;
        if (musicon)
        {
            PlaySound(0,0,0);
            PlaySound("flight.wav",NULL,SND_ASYNC);
        }

    }
//place your codes for other keys here
}
void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_UP)//|| key==GLUT_KEY_LEFT)
    {

        if(consol==2 && consolout== 2)
        {
            if(check == 0 && ang <=88)
            {
                ang +=2;
                angle=pi*ang /180;
                xshow=100*cos(angle);
                yshow=100*sin(angle);

            }
        }
    }
    if(key == GLUT_KEY_DOWN)//||key==GLUT_KEY_RIGHT)
    {

        if(consol==2 && consolout== 2)
        {
            if(check == 0 && ang >=2)
            {
                ang -=2;
                angle=pi*ang /180;
                xshow=100*cos(angle);
                yshow=100*sin(angle);
            }
        }
    }
    if( key == GLUT_KEY_LEFT)
    {
        ;
    }
    if( key == GLUT_KEY_RIGHT)
    {
        ;
    }


//place your codes for other keys here
}
int main()
{
    //place your own initialization codes here.
    iSetTimer(10,projectile);//0
    iSetTimer(10,mapp);//1
    iSetTimer(10,startupdate);//2
    iSetTimer(1000,startdotupdate);//3
    menumusic();
    FILE *fp=fopen("high score.txt","r");
    if (fp== NULL)
        exit(1);
    for (int i=0;i<5;i++)
    {
        fscanf(fp,"%s %d",arr[i].name,&arr[i].score);
    }
    iInitialize(1000, 500, "ibirds");
    return 0;
}
