#include<graphics.h>
#include<time.h>

using namespace std;
main()
{
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    time_t rawTime;
    struct tm * currentTime;//tm is struct name and *currentTime is pointer variable.
    char a[100];
    /*
    *time_t type variable is useful for representing times which are returned by time() funcion
    *created a pointer variable of tm struct, variable name is currentTime
    *this tm struct is from time.h
    *tm struct contains 9 members of type int.see pic for definition
    */
    while(1)
    {
    rawTime = time(NULL);//this variable holds the no of seconds elapsed since the unix epoch
    currentTime = localtime(&rawTime);
    /*
    *localtime() function takes one argument i.e a time_t object here that is rawTime variable
    *localtime() function uses the value of rawTime to fill the currentTime struct.
    *localtime() return a pointer to a tm struct wit hall the time information filled in its members and we know that
        currentTime is a pointer variable so we assigned localtime to currentTime
        **pointer variable(currenttime)=address localtime(address)
    */
    strftime(a, 100, "%I:%M:%S",currentTime);//strftime is declared in time.h
    //a is the char string, 100 is the max length of the string, 3rd argument is the format specifiers for hour min and seconds, last is the tm pointer variable
    /*
    *   %p is for am-pm
    *   %a is for abbreviated name of the weekday
    *   %d is for date that is day of the month(1-31)
    *   %b is for abbreviated month name
    *   %y is for year
    */
    setcolor(11);
    settextstyle(3, HORIZ_DIR, 10);
    outtextxy(200, 100, a);

    strftime(a, 100, "%p", currentTime);//for am pm
    settextstyle(3, HORIZ_DIR, 2);
    outtextxy(600, 8, a);

    strftime(a, 100, "%a, %d %b, %Y", currentTime);//for the complete date
    settextstyle(3, HORIZ_DIR, 5);
    outtextxy(130, 310, a);

    delay(1000);

    }

    getch();
    closegraph();
}
