#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set1.h"


#ifdef C3
int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    char *a = argv[1];
    int n = strlen(a);
    for (int i = 0; i < 16; i++) {
        char c = decToHex(i);
        char b[n + 1];
        b[n] = '\0';
        for (int i = 0; i < n; i++) {
            b[i] = c;
        }

        printf("%s\n", stringXor(a, b));
    }
}
#endif
