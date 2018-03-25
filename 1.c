#include <string.h>
#include <stdio.h>


char base64alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    char *hex = argv[1];
    int n = strlen(hex);
    int nPrime = (n * 4) / 6;
    char encoded[nPrime + 1];
    encoded[nPrime] = '\0';
    int dec = 0;
    int j = 0;
    int mask = (1 << 6) - 1;
    for (int i = n - 1; i >= 0; i--) {
        int c;
        if (hex[i] < 'a') {
            c = hex[i] - '0';
        } else {
            c = 10 + hex[i] - 'a';
        }

        dec += c << (j++ * 4);
        if (j == 6) {
            for (int k = 0; k < 4; k++) {
                char c = base64alphabet[dec & mask];
                dec = dec >> 6;
                encoded[--nPrime] = c;
            }

            j = 0;
            dec = 0;
        }
    }

    printf("%s\n", encoded);
}
