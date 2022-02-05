// Digital clock with an alarm
// I made a small project of digital clock with alarm concept with the help of for loops and windows.h library
// 1) To slower down the execution happening in seconds loop Sleep() func is used
// 2) To make an alarm sound Beep() func is used in a loop
#include <windows.h>
#include <stdio.h>
#include <time.h>

int main()
{

    int mm, ss, hh, hours, minutes, seconds, n;
    printf("Enter time in HH:MM:SS \n");
    scanf("%d", &hours);
    scanf("%d", &minutes);
    scanf("%d", &seconds);
    printf("\nDo you want to set an alarm ?\n");
    printf("1.Yes || 2.No\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("\nEnter time in HH:MM:SS to set alarm clock \n");
        scanf("%d %d %d", &hh, &mm, &ss);

        break;
    case 2:
        goto start;
        break;
    default:
        printf("Please enter valid format ");
        break;
    }
start:
    for (hours; hours < 24; hours++)
    {
        for (minutes; minutes < 60; minutes++)
        {
            for (seconds; seconds < 60; seconds++)
            {
                system("CLS");
                printf(" %d : %d : %d  ", hours, minutes, seconds);
                if (hh == hours && mm == minutes && ss == seconds)
                {
                    printf("Wake up \n ");
                    for (int k = 0; k < 10; k++)
                    {
                        Beep(750, 800);
                    }
                }

                if (hours > 12)
                {
                    printf(" PM ");
                }
                else
                {
                    printf(" AM ");
                }
                Sleep(1000);
            }
            seconds = 0;
        }
        minutes = 0;
    }
    hours = 0;
    goto start;
    return 0;
}
