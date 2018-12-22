#include<graphics.h>
#include<stdio.h>
using namespace std;
main()
{
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    char a[50];
    int countdown;
    printf("Enter number of seconds left: ");
    scanf("%d",&countdown);
    settextstyle(7,HORIZ_DIR,5);

    for(int i=countdown;i>0;i--)
    {
        sprintf(a, "New year is in %d seconds !!", i);
        outtextxy(10,210,a);
        delay(1000);
        cleardevice();
    }

    settextstyle(10, HORIZ_DIR, 6);
    setcolor(YELLOW);
    outtextxy(30,200, "Happy New Year! :-)*");

    delay(500);
    setcolor(LIGHTBLUE);
    outtextxy(30,300, "Happy New Year! :-)*");

    delay(500);
    setcolor(LIGHTGREEN);
    outtextxy(30,100, "Happy New Year! :-)*");


    getch();
    closegraph();
}
