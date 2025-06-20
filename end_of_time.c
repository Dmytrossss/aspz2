#include <stdio.h>
#include <time.h>
#include <limits.h>

int main() {
    printf("Розмір time_t: %ld байт\n", sizeof(time_t));
    
    if (sizeof(time_t) == 4) {
        time_t max_time = INT_MAX;
        printf("32-бітний time_t закінчиться: %s", ctime(&max_time));
    } else {
        printf("64-бітний time_t закінчиться приблизно у 292,277,026,596 років\n");
    }
    
    return 0;
}
