#include "uop_msb.h"
using namespace uop_msb;

// Hardware Definitions
#define TRAF_RED1_PIN PC_2

// Inputs
DigitalIn SW_BLUE(USER_BUTTON);

// Outputs
DigitalOut ledRed(TRAF_RED1_PIN);
DigitalOut ledGreen(PC_3);

// Timer(modified version from Timer)
TimerCompat tmr1;

int main()
{

    tmr1.start();
    while (1<2)
    {


    while (SW_BLUE ==1)
    {
    if (tmr1.elapsed_time() > 1000ms && SW_BLUE == 1 )
    {
        if (SW_BLUE == 0)
        {
            if (tmr1.elapsed_time()> 1000ms && SW_BLUE ==0)
            {
                ledRed = !ledRed;
            }

        }
    }
    }

}
}
