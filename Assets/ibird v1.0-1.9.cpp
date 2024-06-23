# include "iGraphics.h"
#include<stdio.h>
#include<math.h>
const float pi=acos(0)*2;
const float g=10;
//for scoring
int score[5]={0};
char p1[5],p2[5],p3[5],p4[5],p5[5];
//for coordinates of the ball
float xball=75,yball=75;
//for angles
float ang;
float angle=pi*ang /180;
//
float xshow=50*cos(angle);
float yshow=50*sin(angle);
int check;
//for time
float t=0,tcol,tmax;
// for velocities
int mapping;
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
int dark,music,sound;
// debugging variable
int hudai=0;
//for pigs/gems
int gem1,gem2,gem3,gem4,gem5,gem6;
//for number of turns
int num;
int backgnd;
int level;
int running;
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
        if(startx==1000)
        {
            iPauseTimer(2);
            iPauseTimer(3);
            consol++;
        }
    }

}

// this func will tell us which bird will tell us what not implemented until now
void birds()
{
    if (bird == 0)
    {

    }
    if (bird == 1)
    {
        if (birdstate%2== 1)
        {
            v=v*3;
        }
    }
    if (bird == 2)
    {

    }
    if (bird ==3)
    {

    }
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
void projectile()//projectile with collision also has gems
{
    if(check ==2)
    {
        if((abs(vx)>0.005 || abs(vy)>0.005) && xball>0 && xball<1250 && yball>5)
        {
            //int dx=-1;
            t=t+0.05;
            running=1;
            if(xball>=500 && xball<=510)
            {
                if (yball>=200 &&yball<=240  && col!=1)
                {
                        col=1;
                        x=xball;
                        y=yball;
                        vx=-vx/5;
                        vy=vy-g*(t-tcol);
                        tcol=t;
                }
            }
            else if(xball >=600 && xball<=610)
            {
                if(yball>=150 && yball<= 200 && col != 2)
                {
                    col=2;
                    x=xball;
                    y=yball;
                    vx=vx/4;
                    vy=vy-g*(t-tcol);
                    tcol=t;
                }
            }
            else if (xball>=510 && xball <=550 && col != 3)
            {
                if (yball >=240 && yball <=255)
                {
                    col=3;
                    x=xball;
                    y=yball;
                    vx=vx/2;
                    vy=-(vy-g*(t-tcol))/2;
                    tcol=t;

                }
            }
            else if (xball>=495 && xball <= 510)
            {
                if (yball >=240 && yball <=255 && col !=4)
                {
                    col=4;
                    x=xball;
                    y=yball;
                    vx=-vx/5;
                    vy=-((vy-g*(t-tcol))/5);
                    tcol=t;

                }
            }
            else if (yball<=20 && col!=3)
            {
                col=3;
                x=xball;
                y=yball;
                vx=vx/1.2;
                vy=-(vy-g*(t-tcol))/2;
                tcol=t;
            }
            if(col==1)
            {
                xball=x+vx*(t-tcol);
                yball=y+vy*(t-tcol)-0.5*g*(t-tcol)*(t-tcol);
                if(xball<=500 || xball>=510 || yball<=200 || yball>=240)
                {
                    col=0;
                }

            }
            else if(col==2)
            {
                xball=x+vx*(t-tcol);
                yball=y+vy*(t-tcol)-0.5*g*(t-tcol)*(t-tcol);
                if(xball <=600 || xball>=610 || yball<=150 || yball>= 200)
                {
                    col=0;
                }
            }
            else if (col ==3)
            {
                xball=x+vx*(t-tcol);
                yball=y+vy*(t-tcol)-0.5*g*(t-tcol)*(t-tcol);

                if (xball<=510 || xball >=550 || yball <=240 || yball >=255)
                {
                    if (yball>=20)
                    {
                        col=0;
                    }
                }
            }
            else if (col== 4)
            {
                xball=x+vx*(t-tcol);
                yball=y+vy*(t-tcol)-0.5*g*(t-tcol)*(t-tcol);
                if(xball<=495 || xball >= 510 || yball <=240 || yball >=255)
                {
                    col=0;
                }
            }
            else
            {
                xball=vx*(t-tcol)+x;
                yball=vy*(t-tcol)-0.5*g*(t-tcol)*(t-tcol)+y;
            }
            if(xball >=800 && xball<=824 )
            {
                if(yball>=20 && yball<=42)
                {
                    gem1=1;
                }

                if (gem1!=1)
                    gem1=0;
            }

            else if(xball >=700 && xball<=724)
            {
                if(yball>=20 && yball<=38)
                {
                    gem2=1;
                }
                if (gem2!=1)
                    gem2=0;
            }
            else if(xball >=900 && xball<=924)
            {
                if(yball>=20 && yball<=42 )
                {
                    gem3=1;
                }
                if (gem3!=1)
                    gem3=0;
            }
            else if(xball >=850 && xball<=874)
            {
                if(yball>=20 && yball<=38)
                {
                    gem4=1;
                }
                if (gem4!=1)
                    gem4=0;
            }
            else if(xball >=750 && xball<=774)
            {
                if(yball>=20 && yball<=42)
                {
                    if(level==1||level==2)
                    {
                        gem5=1;
                    }
                }
                if (gem5!=1)
                    gem5=0;
            }
            else if(xball >=825 && xball<=849)
            {
                if(yball>=20 && yball<=38)
                {
                    if(level==2)
                    {
                        gem6=1;
                    }
                }
                if (gem6!=1)
                    gem6=0;
            }


        }
        else
        {
            tcol=t=0;
            running=0;
            check=0;
            mapping=col=0;
            direction=1;
            xball=yball=75;
            x=xball;
            y=yball;
            num++;
        }
        //the console 3 can be only operated by the console 2 as an input this if is done when game is over
        if(num==5 && gem1==0 && gem2==0 && gem3==0 && gem4==0 && gem5==0 && gem6==0)
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
        }
        if(num==5 && gem1==1||num==5 && gem2==1|| num==5 && gem3==1||num==5 && gem4==1||num==5 && gem5==1||num==5 && gem6==1)
        {
            level++;
            num=0;
            gem1=0;
            gem2=0;
            gem3=0;
            gem4=0;
            gem5=0;
            gem6=0;
            consol=3;
            consol2out=2;
            if (level==3)
            {
                level=0;
                consol=3;
                consol2out=3;
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
        //user presses continue
        if (consolout==1)
        {
            iText(400,400,"this section is still developing",GLUT_BITMAP_TIMES_ROMAN_24);
//            iCircle(55,450,35,1000);
//            iText(24,442,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
            iShowBMP2(55-35,420,"backicon.bmp",0);
        }
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
//            iCircle(55,450,35,1000);
//            iText(24,442,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
            iShowBMP2(55-35,420,"backicon.bmp",0);
            iSetColor(255,0,0);
            //for power indicator
            iRectangle(10,20,8,101);
            iFilledRectangle(11,21,6,mapping);
            //
            //axis drawing
            iLine(0,1,800,1);
            iLine(1,0,1,650);
            //
            //iSetColor(255,255,255);
            //iCircle(75,75,80,1000);
            iSetColor(0,0,255);
            //showing line
            iLine(75,75,xshow+75,yshow+75);
            iSetColor(255,0,0);
            //non removable obstacle
            iFilledRectangle(500,200,10,40);
            iFilledRectangle(510,240,40,10);
            iSetColor(125,125,125);
            iFilledRectangle(500,240,10,10);
            //iFilledRectangle(500,200,50,50);
            if(col!= 2)
            {
                iSetColor(0,255,0);
                //removable obstacle
                iFilledRectangle(600,150,10,50);
            }
            iText(800,442,"SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
            //iLine(100,240,800,240);
            iSetColor(0,0,255);
            iFilledCircle(xball,yball,5,1000);
            if(level==0)
            {

                if(gem1==0)
                {
                    iFilledRectangle(800,20,24,24);
                    //iShowBMP2(800,20,"icon_2.bmp",0);
                }
                if(gem2==0)
                {
                    iFilledRectangle(700,20,24,24);
                    //iShowBMP2(700,20,"icon_3.bmp",0);
                }
                if(gem3==0)
                {
                    iFilledRectangle(900,20,24,24);
                    //iShowBMP2(900,20,"icon_2.bmp",0);
                }
                if(gem4==0)
                {
                    iFilledRectangle(850,20,24,24);
                    //iShowBMP2(850,20,"icon_3.bmp",0);
                }
                /*
                if(gem5==0)
                {
                    iFilledRectangle(750,20,24,24);
                    //iShowBMP2(750,20,"icon_2.bmp",0);
                }
                if(gem6==0)
                {
                    iFilledRectangle(825,20,24,24);
                    //iShowBMP2(825,20,"icon_3.bmp",0);
                }
                */
            }

            if(level==1)
            {
                if(gem1==0)
                {
                    iFilledRectangle(800,20,24,24);
                    //iShowBMP2(800,20,"icon_2.bmp",0);
                }
                if(gem2==0)
                {
                    iFilledRectangle(700,20,24,24);
                    //iShowBMP2(700,20,"icon_3.bmp",0);
                }
                if(gem3==0)
                {
                    iFilledRectangle(900,20,24,24);
                    //iShowBMP2(900,20,"icon_2.bmp",0);
                }
                if(gem4==0)
                {
                    iFilledRectangle(850,20,24,24);
                    //iShowBMP2(850,20,"icon_3.bmp",0);
                }
                if(gem5==0)
                {
                    iFilledRectangle(750,20,24,24);
                    //iShowBMP2(750,20,"icon_2.bmp",0);
                }/*
                if(gem6==0)
                {
                    iFilledRectangle(825,20,24,24);
                    //iShowBMP2(825,20,"icon_3.bmp",0);
                }*/
            }
            if(level==2)
            {
                if(gem1==0)
                {
                    iFilledRectangle(800,20,24,24);
                    //iShowBMP2(800,20,"icon_2.bmp",0);
                }
                if(gem2==0)
                {
                    iFilledRectangle(700,20,24,24);
                    //iShowBMP2(700,20,"icon_3.bmp",0);
                }
                if(gem3==0)
                {
                    iFilledRectangle(900,20,24,24);
                    //iShowBMP2(900,20,"icon_2.bmp",0);
                }
                if(gem4==0)
                {
                    iFilledRectangle(850,20,24,24);
                    //iShowBMP2(850,20,"icon_3.bmp",0);
                }
                if(gem5==0)
                {
                    iFilledRectangle(750,20,24,24);
                    //iShowBMP2(750,20,"icon_2.bmp",0);
                }
                if(gem6==0)
                {
                    iFilledRectangle(825,20,24,24);
                    //iShowBMP2(825,20,"icon_3.bmp",0);
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
//            iCircle(55,450,35,1000);
//            iText(24,442,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
            iShowBMP2(55-35,420,"backicon.bmp",0);
            iText(100,200,"kal eee ct tar poreo ami aj game banaitesi .....c cz mama pera ani chill!!!!!!!",GLUT_BITMAP_TIMES_ROMAN_24);
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
            }/*
            if(dark ==1)
            {
                iShowBMP2(450,20,"tick sign.bmp",0);
            }*/
            iRectangle(200,20,200,35);
            iRectangle(450,20,35,35);
            iText(200,31,"DARK MODE",GLUT_BITMAP_TIMES_ROMAN_24);
            iRectangle(450,60,35,35);
            iRectangle(450,100,35,35);
            iRectangle(200,60,200,35);
            iRectangle(200,100,200,35);
//            iCircle(55,450,35,1000);
//            iText(24,442,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
            iShowBMP2(55-35,420,"backicon.bmp",0);
        }
        //high score
        if (consolout==5)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"angry bird consol 1.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird consol 1 dark mode.bmp");
            }
            iSetColor(0,0,0);
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
//            iCircle(55,450,35,1000);
//            iText(24,442,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
            iShowBMP2(55-35,420,"backicon.bmp",0);

            iText(205,31,"scorename[0]",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(205,71,"scorename[1]",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(205,111,"scorename[2]",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(205,151,"scorename[3]",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(205,191,"scorename[4]",GLUT_BITMAP_TIMES_ROMAN_24);

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
//            iCircle(55,450,35,1000);
//            iText(24,442,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
            iShowBMP2(55-35,420,"backicon.bmp",0);
            iText(100,200,"game er background joss hoise na??????????",GLUT_BITMAP_TIMES_ROMAN_24);
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
            iSetColor(0,0,255);
           iShowBMP2(260,100,"consol 3 sure.bmp",0);

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
            iFilledEllipse(350,200-20,50,20,100);
            //iFilledEllipse(500,200,50,20,100);
            iFilledEllipse(650,200-20,50,20,100);
            iSetColor(255,255,255);
            iText(422,240,"GAME OVER!!",GLUT_BITMAP_TIMES_ROMAN_24);
            iShowBMP2(350-35,180-35,"backcir.bmp",0);
            iShowBMP2(500-35,180-35,"retry.bmp",0);
            iShowBMP2(650-35,180-35,"forward.bmp",0);
            iShowBMP2(650-35,180-35,"off.bmp",0);
            iSetColor(0,0,0);
            iText(422,100,"Your Score:",GLUT_BITMAP_TIMES_ROMAN_24);
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
            iText(422,100,"Your Score:",GLUT_BITMAP_TIMES_ROMAN_24);
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
            iShowBMP2(500-35,180-35,"off.bmp",0);
            iSetColor(0,0,0);
            iText(422,100,"Your Score:",GLUT_BITMAP_TIMES_ROMAN_24);
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
        iSetColor(0,0,255);
        iRectangle(300,175,400,200);
        iText(350,325,"Do you want to save the game?",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,255,0);
        iShowBMP2(360,200,"cross.bmp",0);
        iShowBMP2(540,200,"tickicon.bmp",0);
    }

}
void iMouseMove(int mx, int my)
{
//place your codes here
    ;
}
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(consol == 1)
        {
            if(mx>=395 && mx<=605 && my>=260 && my<=295)
            {
                consol++;
                consolout=1;
            }
            if(mx>=395 && mx<=605 && my>=220 && my<=255)
            {
                consol++;
                consolout=2;
                angle=0;
                xshow=50*cos(angle);
                yshow=50*sin(angle);
                num=0;
                gem1=gem2=gem3=gem4=gem5=gem6=0;
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
            if (consolout==1)
            {
                if(mx>=55-35 && mx<=55+35 && my>=450-35 && my<=450+35)
                {
                    consol--;
                    consolout=0;
                }
            }
            if (consolout==2)
            {
                if(mx>=55-35 && mx<=55+35 && my>=450-35 && my<=450+35)
                {
                    consol++;
                    consol2out=0;
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
                if(mx>=295 && mx<=365 && my>=170 && my<=240)//no
                {
                    consol=2;
                    consolout=2;
                }
                if(mx>=605 && mx<=675 && my>=170 && my<=240)//yes
                {
                    consol++;
                }
            }
            if(consol2out==1)//game over
            {
                if(mx>=300 && mx<=400 && my >=160 && my<=200)//back
                {
                    consol++;
                    consol2out=0;
                }
                if(mx>=600 && mx<=700 && my>160 && my<=200)//retry
                {
                    consol=2;
                    consolout=2;
                    angle=0;
                    xshow=50*cos(angle);
                    yshow=50*sin(angle);
                }
            }
            if(consol2out==2)//level clear
            {
                if(mx>=300 && mx<=400 && my >=160 && my<=200)//back
                {
                    consol++;
                    consol2out=0;
                }
                if(mx>=600 && mx<=700 && my>160 && my<=200)//forward
                {
                    consol=2;
                    consolout=2;
                    ang=0;
                    angle=0;
                    xshow=50*cos(angle);
                    yshow=50*sin(angle);

                }
                if(mx>=450 && mx<=550 && my>160 && my<=200)//replay
                {
                    consol=2;
                    consolout=2;
                    level--;
                    ang=0;
                    angle=0;
                    xshow=50*cos(angle);
                    yshow=50*sin(angle);
                }
            }
            if(consol2out==3)//last level clear
            {
                if(mx>=300 && mx<=400 && my >=160 && my<=200)//back
                {
                    consol++;
                    consol2out=0;
                }
                if(mx>=600 && mx<=700 && my>160 && my<=200)//play again
                {
                    consol=2;
                    consolout=2;
                    ang=0;
                    angle=0;
                    xshow=50*cos(angle);
                    yshow=50*sin(angle);

                }
            }
        }
        if(consol==4)//do you want to save the game ?
        {
            if(mx>=360 && mx<=360+80 && my>=200 && my<=250)//no
            {
                consol=1;
                consolout=0;
                iResumeTimer(4);
                consolout=0;
                t=0;
                check=0;
                mapping=col=0;
                direction=1;
                xball=yball=75;
            }
            if(mx>=540 && mx<=540+80 && my>=200 && my<=250)//yes
            {
                consol=1;
                consolout=0;
                iResumeTimer(4);
                consolout=0;
                t=0;
                check=0;
                mapping=col=0;
                direction=1;
                xball=yball=75;
            }
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
        if (check==0 || check == 1)
            check ++;
    }
    if(check == 0 || check ==2)
    {
        iPauseTimer(1);
    }
    if(check ==1 )
    {
        iResumeTimer(1);
    }
    if (check == 2 && running==0)

    {
        v=mapping;
        vx=vxi=v*cos(angle);
        vy=vyi=v*sin(angle);
        tmax=5*vyi/g;
    }

//place your codes for other keys here
}
void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_UP)
    {

        if(consol==2 && consolout== 2)
        {
            if(check == 0 && ang <=88)
            {
                ang +=2;
                angle=pi*ang /180;
                xshow=50*cos(angle);
                yshow=50*sin(angle);

            }
        }
    }
    if(key == GLUT_KEY_DOWN)
    {

        if(consol==2 && consolout== 2)
        {
            if(check == 0 && ang >=2)
            {
                ang -=2;
                angle=pi*ang /180;
                xshow=50*cos(angle);
                yshow=50*sin(angle);
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
void debug()
{
    if(consol==2 && consolout==2 && xball!=75 && yball!=75 )
    {
        printf("vx=%f vy=%f x=%f y=%f tcol=%f t=%f col=%d\n",vx,vy,x,y,tcol,t,col);
    }
}
int main()
{
    //place your own initialization codes here.
    iSetTimer(2,projectile);//0
    iSetTimer(10,mapp);//1
    iSetTimer(10,startupdate);//2
    iSetTimer(400,startdotupdate);//3
    iInitialize(1000, 500, "ibirds");
    return 0;
}
