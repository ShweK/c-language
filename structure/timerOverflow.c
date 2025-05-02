#include <stdio.h>

struct Timer {
    unsigned int count;
    unsigned int reload;
    unsigned char enable;
};
struct Timer timer_v;
void startTimer()
{
   do{
    timer_v.count++;
   }while(timer_v.count);
   timer_v.reload++;
   if(timer_v.reload < 2)
   {
    startTimer();
   }
   printf("Return\n");
   return;

}

int main()
{

    printf("enable the timer:");
    scanf("%c",&timer_v.enable);
    if(timer_v.enable == 'y')
    {
        startTimer();
    }

}