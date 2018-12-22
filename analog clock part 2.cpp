//made the clock gave it no's and made the hour hand that points to the current time
#include<graphics.h>
#include<stdio.h>
#include<time.h>

using namespace std;
main()
{
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    //Coordinates for hour
    /*again found using trigonometry calculator keeping the hypotenuse 100 since the hour hand is usually shorter */
    int coordsForHourX[12] = {50, 87, 100, 87, 50, 0, -50, -87, 100, -87, -50, 0};//this will hold the X coordinates for all the 12 hours on the clock
    int coordsForHourY[12] = {-87, -50, 0, 50, 87, 100, 87, 50, 0, -50, -87, -100};//this will hold the Y coordinates for all the 12 hours on the clock


    //coordinates for minute hand
    //hypotenuse used is 170
    //00 seconds/minutes starts from the top in our clock (at 12 hour), that is why the first point is (0, -170)
    //after 15 seconds/minutes(00 - 14) the coordinates are repeating and = and - sign is switched
    //coordsForMinSecX[60] this will hold the coordinates of X of all 60 min and seconds of our clock
    int coordsForMinSecX[60] = {0,18,35,53,69,85,100,114,126,138,
                                147,155,162,166,169,170,169,166,162,155,
                                147,138,126,114,100,85,69,53,35,18,
                                0,-18,-35,-53,-69,-85,-100,-114,-126,-138,
                                -147,-155,-162,-166,-169,-170,-169,-166,-162,-155,
                                -147,-138,-126,-114,-100,-85,-69,-53,-35,-18};
    //coordsForMinSecY[60] this will hold the coordinates of Y of all 60 min and seconds of our clock
    int coordsForMinSecY[60] = {-170,-169,-166,-162,-155,-147,-138,-126,-114,-100,
                                -85,-69,-53,-35,-18,0,18,35,53,69,
                                85,100,114,126,138,147,155,162,166,169,
                                170,169,166,162,155,147,138,126,114,100,
                                85,69,53,35,18,0,-18,-35,-53,-69,
                                -85,-100,-114,-126,-138,-147,-155,-162,-166,-169};

    //Time related variables
    time_t rawTime;
    struct tm * currentTime;
    char a[100];

    // To get midpoint of the graph

    int midX = getmaxx()/2;
    int midY = getmaxy()/2;

    // Variable for storing hour, minute, and seconds info

    int IMS;//this variable will store hours, minutes, seconds information in integer form
while(1){
    //Time related Functions

    rawTime = time(NULL);
    currentTime = localtime(&rawTime);

    // Drawing the circle

    setcolor(WHITE);
    circle(midX, midY, 200);
    /*see video around 4.5 min/12min for clarification
    *also we found these values using an online trigonometry calculator keeping the value of hypotenuse 190 for keeping the no inside the circle and the angle 60
    *bracket items are just adjustments for the no to be in the right place
    */
    outtextxy(midX+95+(-5), midY-165+(-5), "1");
    outtextxy(midX+165+(-5), midY-95+(-5), "2");
    outtextxy(midX+190+(-5), midY+0+(-7), "3");
    outtextxy(midX+165+(-7), midY+95+(-7), "4");
    outtextxy(midX+95+(-5), midY+165+(-10), "5");
    outtextxy(midX+0+(-3), midY+190+(-10), "6");
    outtextxy(midX-95+(-0), midY+165+(-10), "7");
    outtextxy(midX-165+(-2), midY+95+(-10), "8");
    outtextxy(midX-190+(-3), midY+0+(-7), "9");
    outtextxy(midX-165+(-5), midY-95+(-3), "10");
    outtextxy(midX-95+(-5), midY-165+(-5), "11");
    outtextxy(midX+0+(-6), midY-190+(-5), "12");

    // Getting time info and converting it to integer
    // setting the color and drawing the line
    strftime(a, 100, "%I", currentTime);
    sscanf(a, "%d", &IMS);//sscanf()will read the data from 'a'(char array) and store it in IMS variable.
    setcolor(RED);
    line(midX, midY, midX+coordsForHourX[IMS-1], midY+coordsForHourY[IMS-1]);
    /*
    *see pic
    */

    strftime(a, 100, "%M", currentTime);
    sscanf(a, "%d", &IMS);//sscanf()will read the data from 'a'(char array) and store it in IMS variable.
    setcolor(YELLOW);
    line(midX, midY, midX+coordsForMinSecX[IMS], midY+coordsForMinSecY[IMS]);
    /*
    *see pic for IMS-1 and IMS
    */
    strftime(a, 100, "%S", currentTime);
    sscanf(a, "%d", &IMS);//sscanf()will read the data from 'a'(char array) and store it in IMS variable.
    setcolor(GREEN);
    line(midX, midY, midX+coordsForMinSecX[IMS], midY+coordsForMinSecY[IMS]);
    delay(1000);
    cleardevice();
}

    getch();
    closegraph();
}

