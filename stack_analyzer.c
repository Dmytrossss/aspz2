#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSG "In function %20s; &localvar = %p\n"

static void deepest() {
    int localvar = 5;
    printf(MSG, __FUNCTION__, &localvar);
    printf("PID: %d\n", getpid());
    pause();
}

static void middle() {
    int localvar = 5;
    printf(MSG, __FUNCTION__, &localvar);
    deepest();
}

static void outer() {
    int localvar = 5;
    printf(MSG, __FUNCTION__, &localvar);
    middle();
}

int main() {
    int localvar = 5;
    printf(MSG, __FUNCTION__, &localvar);
    outer();
    return 0;
}
