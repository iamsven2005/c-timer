#include <stdio.h>
#include <time.h>
#include <emscripten.h>

time_t start_time;
int is_running = 0;

// Function to start the stopwatch/timer
EMSCRIPTEN_KEEPALIVE
void start_timer() {
    if (!is_running) {
        start_time = time(NULL);
        is_running = 1;
    }
}

// Function to stop the stopwatch/timer
EMSCRIPTEN_KEEPALIVE
void stop_timer() {
    if (is_running) {
        time_t end_time = time(NULL);
        printf("Elapsed time: %lld seconds\n", (long long)(end_time - start_time));
        is_running = 0;
    }
}

// Function to get the elapsed time without stopping
EMSCRIPTEN_KEEPALIVE
int get_elapsed_time() {
    if (is_running) {
        return (int)(time(NULL) - start_time);
    }
    return 0;
}
