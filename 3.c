#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set1.h"


#ifdef C3
int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    uchar *a = (uchar *) argv[1];
    int n = strlen((char *) a);
    uchar *decoded = hexDecode(a, n);
    for (int k = 32; k <= 126; k++) {
        uchar c = (uchar) k;
        uchar b[n / 2 + 1];
        b[n] = '\0';
        for (int i = 0; i < n / 2; i++) {
            b[i] = c;
        }

        uchar *result = stringXor(a, b, n / 2);
        int i;
        int foundUnprintable = 0;
        for (i = 0; i < n / 2; i++) {
            int isPrintableChar = result[i] >= 32 && result[i] <= 126;
            if (!isPrintableChar) {
                //foundUnprintable = 1;
                break;
            }
        }
        if (!foundUnprintable) {
            printf("%c: %s\n", c, stringXor(a, b, n / 2));
        }
    }
}
#endif
