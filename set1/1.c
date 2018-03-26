#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set1.h"


const uchar base64alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


uchar hexToDec(uchar hex) {
    if (hex < 'a') {
        return hex - '0';
    } else {
        return 10 + hex - 'a';
    }
}


uchar * hexToBase64(uchar *hex) {
    int n = strlen((char *) hex);

    // Compute the length of the base64 string. One hex digit is 4 bits. The
    // length of the bit representation of the hex string is divided into
    // groups of 6 bits. The length of the bit representation of the base64
    // string must be a multiple of 6 to make room for padding.
    int nEncoded = (n * 4) / 6;
    if (nEncoded % 4 != 0) {
        nEncoded += 4 - (nEncoded % 4);
    }

    uchar *encoded = malloc(sizeof(uchar) * (nEncoded + 1));
    encoded[nEncoded] = '\0';

    int dec = 0;
    int j = 0;
    for (int i = n - 1; i >= 0; i--) {
        int c = hexToDec(hex[i]);
        dec += c << (j++ * 4);

        // We've formed a 24-bit block (4 bits per hex digit * 6 hex digits).
        if (j == 6) {
            while (dec > 0) {
                uchar c = base64alphabet[dec & MASK_64];
                dec = dec >> 6;
                encoded[--nEncoded] = c;
            }

            // Reset for the next 24-bit block.
            j = 0;
            dec = 0;
        }
    }

    // Padding example:
    // 6    f    6    d
    // 0110 1111 0110 1101
    // 0110 1111 0110 1101 0000 0000
    // bbbb bb22 2222 0000 00== ====
    if (j > 0) {
        // How far were we off from a 24-bit block?
        int diff = 6 - j;
        // How many 6-bit groups should be padding?
        int padding = (diff * 4) / 6;
        dec = dec << (4 * diff);
        while (dec > 0) {
            uchar c;
            if (padding > 0) {
                c = '=';
                padding--;
            } else {
                c = base64alphabet[dec & MASK_64];
            }
            dec = dec >> 6;
            encoded[--nEncoded] = c;
        }
    }

    return encoded;
}


#ifdef C1
int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    uchar *hex = (uchar *) argv[1];
    char *base64 = (char *) hexToBase64(hex);
    printf("%s\n", base64);
    free(base64);

    return 0;
}
#endif
