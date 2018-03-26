#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set1.h"


int scoreEnglishCandidate(uchar *str, unsigned int len) {
    unsigned int numSpaces = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            numSpaces++;
        }
    }
    return numSpaces;
}


#ifdef C3
int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    uchar *bestResult = NULL;
    int bestScore = 0;
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

        uchar *result = stringXor(decoded, b, n / 2);
        int score = scoreEnglishCandidate(result, n / 2);
        if (score > bestScore) {
            bestScore = score;
            bestResult = result;
        }
    }

    printf("Best result: %s\n", bestResult);

    return 0;
}
#endif
