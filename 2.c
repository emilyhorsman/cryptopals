#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char hexToDec(char hex) {
    if (hex < 'a') {
        return hex - '0';
    } else {
        return 10 + hex - 'a';
    }
}



char decToHex(char dec) {
    if (dec >= 10) {
        return 'a' + dec - 10;
    } else {
        return '0' + dec;
    }
}


char * xor(char *a, char *b) {
    int n = strlen(a);
    char *output = malloc(sizeof(char) * (n + 1));
    output[n] = '\0';

    for (int i = 0; i < n; i++) {
        char x = hexToDec(a[i]);
        char y = hexToDec(b[i]);
        char z = decToHex(x ^ y);
        output[i] = z;
    }

    return output;
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 1;
    }

    char *bufferA = argv[1];
    char *bufferB = argv[2];
    char *s = xor(bufferA, bufferB)
    printf("%s\n", s);
    free(s);
}
