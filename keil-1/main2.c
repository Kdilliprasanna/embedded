#include <REGX51.H>

void delay()
{
    unsigned int i,j;

    for(i=0;i<200;i++)
        for(j=0;j<1275;j++);
}

void main()
{
    unsigned char object_detect;
    unsigned char overload;
    unsigned char emergency;

    while(1)
    {
        /* Simulated Inputs */

        object_detect = 1;
        overload = 0;
        emergency = 0;

        /* Object Detection */

        if(object_detect)
            P1_0 = 1;
        else
            P1_0 = 0;

        /* Overload Detection */

        if(overload)
            P1_1 = 1;
        else
            P1_1 = 0;

        /* Emergency Stop */

        if(emergency)
            P1_2 = 1;
        else
            P1_2 = 0;

        /* Conveyor Motor */

        if(object_detect && !overload && !emergency)
            P1_7 = 1;      // Motor ON
        else
            P1_7 = 0;      // Motor OFF

        delay();
    }
}