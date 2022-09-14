#include <stdio.h>
#include <Windows.h>
#include <time.h>

void clock_v1();
void clock_v2();

int main() {
    // clock_v1();
    for (int i = 0; i < 60; ++i) {
        clock_v2();
        Sleep(1000);
    }

    return 0;
}

void clock_v1() {
    time_t start, end;

    for (int h = 0; h < 24; ++h) {
        for (int m = 0; m < 60; ++m) {
            start = time(NULL);

            for (int s = 0; s < 60; ++s) {
                printf("%d h %d m %d s \n", h, m, s);
                Sleep(1000);
            }

            end = time(NULL);
            printf("Time taken to print the clock is %.2f seconds \n",
                   difftime(end, start));
        }
    }
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