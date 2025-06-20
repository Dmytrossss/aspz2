#include <stdio.h>

char large_array[1024*1024*10]; // 10 MB у BSS

int main() {
    printf("Програма з великим BSS сегментом\n");
    return 0;
}
