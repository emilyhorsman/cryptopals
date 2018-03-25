#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MASK_64 (1 << 6) - 1


char base64alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


char hexToDec(char hex) {
    if (hex < 'a') {
        return hex - '0';
    } else {
        return 10 + hex - 'a';
    }
}


char * hexToBase64(char *hex) {
    int n = strlen(hex);
    int nEncoded = (n * 4) / 6;
    if (nEncoded % 4 != 0) {
        nEncoded += 4 - (nEncoded % 4);
    }

    char *encoded = malloc(sizeof(char) * (nEncoded + 1));
    encoded[nEncoded] = '\0';

    int dec = 0;
    int j = 0;
    for (int i = n - 1; i >= 0; i--) {
        int c = hexToDec(hex[i]);
        dec += c << (j++ * 4);

        if (j == 6) {
            while (dec > 0) {
                char c = base64alphabet[dec & MASK_64];
                dec = dec >> 6;
                encoded[--nEncoded] = c;
            }

            j = 0;
            dec = 0;
        }
    }

    if (j > 0) {
        int diff = 6 - j;
        int padding = (diff * 4) / 6;
        dec = dec << (4 * diff);
        for (; padding > 0; padding--) {
            dec = dec >> 6;
            encoded[--nEncoded] = '=';
        }
        while (dec > 0) {
            char c = base64alphabet[dec & MASK_64];
            dec = dec >> 6;
            encoded[--nEncoded] = c;
        }
    }

    return encoded;
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    char *hex = argv[1];
    char *base64 = hexToBase64(hex);
    printf("%s\n", base64);
    free(base64);

    return 0;
}
