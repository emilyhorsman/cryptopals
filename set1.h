#ifndef _SET_1_H_
#define _SET_1_H_

#define MASK_64 (1 << 6) - 1


typedef unsigned char uchar;


extern const uchar base64alphabet[];

uchar hexToDec(uchar hex);
uchar decToHex(uchar dec);
uchar * hexToBase64(uchar *hex);
uchar * stringXor(uchar *a, uchar *b);
uchar * hexDecode(uchar *hex);

#endif
