#include<stdio.h>

struct time
{
    int hours;
    int minutes;
    int seconds;

};

int main(){
    struct time t1,t2;
    int h,m,s;
    printf("First Time \n");
    printf("Hours : ");
    scanf("%d",&t1.hours);

    printf("Minutes : ");
    scanf("%d",&t1.minutes);

    printf("Seconds : ");
    scanf("%d",&t1.seconds);

    printf("Second Time \n");
    printf("Hours : ");
    scanf("%d",&t2.hours);

    printf("Minutes : ");
    scanf("%d",&t2.minutes);

    printf("Seconds : ");
    scanf("%d",&t2.seconds);

    h=t1.hours+t2.hours;
    m=t1.minutes+t2.minutes;
    s=t1.seconds+t2.seconds;

    printf("Total Hours : %d\n",h);
    printf("Total Minutes : %d\n",m);
    printf("Total Seconds : %d\n",s);
}