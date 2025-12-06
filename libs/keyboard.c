#include "keyboard.h"
#include "io.h"

unsigned char last_scancode = 0;

unsigned char scancode_to_ascii[128] = {
    0, 27, '1','2','3','4','5','6','7','8','9','0','-','=', '\b',
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n', 0,
    'a','s','d','f','g','h','j','k','l',';','\'','`', 0,'\\',
    'z','x','c','v','b','n','m',',','.','/', 0, '*', 0, ' '
};


char keyboard_getchar(void) {
    unsigned char status;
    unsigned char scancode;

    do {
        status = inb(0x64);      
    } while ((status & 1) == 0);

    scancode = inb(KEYBOARD_PORT);

    if (scancode & 0x80) return 0;

    return scancode_to_ascii[scancode];
}
