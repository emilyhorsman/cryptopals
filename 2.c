#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set1.h"


uchar decToHex(uchar dec) {
    if (dec >= 10) {
        return 'a' + dec - 10;
    } else {
        return '0' + dec;
    }
}


uchar * hexDecode(uchar *hex) {
    int n = strlen((char *) hex) / 2;
    uchar *output = malloc(sizeof(uchar) * (n + 1));
    output[n] = '\0';

    for (int i = 0; i < n; i++) {
        uchar c = (hexToDec(hex[i * 2]) << 4) + hexToDec(hex[i * 2 + 1]);
        output[i] = c;
    }

    return output;
}


uchar * hexEncode(uchar *plaintext) {
    int n = strlen((char *) plaintext);
    uchar *output = malloc(sizeof(uchar) * (n * 2 + 1));
    output[n] = '\0';

    for (int i = 0; i < n; i++) {
        uchar a = decToHex(plaintext[i] >> 4);
        uchar b = decToHex(plaintext[i] & 0xFu);
        output[i * 2] = a;
        output[i * 2 + 1] = b;
    }

    return output;
}


uchar * stringXor(uchar *a, uchar *b) {
    int n = strlen((char *) a);
    uchar *output = malloc(sizeof(uchar) * (n + 1));
    output[n] = '\0';

    for (int i = 0; i < n; i++) {
        uchar z = a[i] ^ b[i];
        output[i] = (uchar) z;
    }

    return output;
}


#ifdef C2
int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 1;
    }

    uchar *bufferA = hexDecode((uchar *) argv[1]);
    uchar *bufferB = hexDecode((uchar *)argv[2]);
    printf("Decode A: %s\nDecode B: %s\n", bufferA, bufferB);
    uchar *s = hexEncode(stringXor(bufferA, bufferB));
    printf("%s\n", s);
    free(s);
}
#endif
