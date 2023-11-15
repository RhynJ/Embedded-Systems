#include "mbed.h"

const uint32_t TIMEOUT_MS = 5000;
InterruptIn button(USER_BUTTON);
volatile int countdown = 9;

void trigger()
{
    Watchdog::get_instance().kick();
    countdown = 9;
}

int main()
{
    printf("\r\nTarget started.\r\n");

    //interrupt and thread safe
    Watchdog &watchdog = Watchdog::get_instance();
    //this tells the watch dog how long it had before it reset the system
    watchdog.start(TIMEOUT_MS);
    //the button press will kick the dog and reset the timer back to 9 
    button.rise(&trigger);

    uint32_t watchdog_timeout = watchdog.get_timeout();
    printf("Watchdog initialized to %u ms.\r\n", watchdog_timeout);
    printf("Press BUTTON1 at least once every %u ms to kick the "
           "watchdog and prevent system reset.\r\n", watchdog_timeout);

    while (1) {
        printf("\r%3i", countdown--);
        fflush(stdout);
        ThisThread::sleep_for(1ms * (TIMEOUT_MS / 10));
    }
}





