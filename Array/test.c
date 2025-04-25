#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "ilovebangladesh";
    // printf("%d %d\n", sizeof(s), strlen(s)); // sizeof char/string er last e null('0') soho cnt kore
    // printf("%%") ;// % print korte arkta % lage;
    // printf("/%"); // output : /
    //Escape sequences in C are special character combinations that begin with a backslash (\) and represent characters that are either 
    //non-printable or have special meanings (like newline, tab, etc.).
    // printf("\%"); // output : \% is not a valid escape sequence in C.
    printf("%d %d\n", '\300', '\x300'); // \300 is octal and \x300 is hex num 
        //since %d use kora hoiche oct and hex dec e convert hobe
        // octa(300) = 3*8^2 + 0*8^1 + 0*8^0 = 3*64 + 0 + 0 = 192 to dec = 128 - 192 =  -64 (8 bit signed int = 2^7 = 128)
        // \x300 = 3*16^2 + 0*16^1 + 0*16^0 = 3* 256 + 0 + 0 = 768 to dec = 128 - 192 =  -64 (8 bit signed int = 2^7 = 128)
        // '\x300' — Hex escape
        // Hex \x300 = 768 in decimal
        // But you got 0 — huh?
        // 👉 Likely reason: Your compiler or environment is only interpreting the lower 8 bits (1 byte) when initializing the character constant.
        // 768 = 0x0300 → binary: 00000011 00000000
        // Lower 8 bits = 00000000 → 0

    // printf("%d\n", sizeof('\tABC\220')); // output : 4
    // printf("%d\n", sizeof("\tABC\220")); // output : 4
    // printf("%d\n", sizeof("\'220")); // output : 3
    // printf("abd\b\bc"); // output : ac \b = backspace
    // printf("\f");
    printf("%hhd\n", 369);
    printf("%hd\n", 369);
    return 0;
}
