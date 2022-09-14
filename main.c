#include <stdio.h>
#include <Windows.h>
#include <time.h>

void clock_v2();

int main() {

    // Runs for a day
    for (int i = 0; i < 60*60*24; ++i) {
        clock_v2();
        Sleep(1000);
    }

    return 0;
}

void clock_v2() {
    time_t rawtime;
    struct tm* timeinfo;

    // Used to store the time
    // returned by localetime() function
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80,
             "Time is %H:%M:%S",
             timeinfo);

    // strftime() function stores the
    // current time as Hours : Minutes
    //%I %M and %p-> format specifier
    // of Hours minutes and am/pm respectively*/

    // prints the formatted time
    puts(buffer);

}