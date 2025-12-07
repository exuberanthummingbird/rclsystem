#include "vga.h"
#include "io.h"

unsigned int cursor;
unsigned int cursor_pos;
unsigned int blink_timer = 0;

void printstr(const char *str) {
    unsigned int j = 0;
    while (str[j] != '\0') {
        VIDMEM[cursor] = str[j];
        VIDMEM[cursor+1] = 0x07;
        ++j;
        cursor += 2;
    }
}

void newline() {
    cursor = (cursor / (80*2) + 1) * (80*2);
}


void putchar(char c) {
    VIDMEM[cursor] = c;
    VIDMEM[cursor+1] = 0x07;
    cursor += 2;
}

void clearscreen(void) {
    unsigned int j = 0;
    while (j < 80*25*2) {
        VIDMEM[j] = ' ';
        VIDMEM[j+1] = 0x07;
        j += 2;
    }
        cursor = 0;
}

void update_cursor(void) {
    unsigned short pos = (unsigned short)(cursor_pos / 2);
    outb(0x3D4, 0x0F);
    outb(0x3D5, (unsigned char)(pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (unsigned char)((pos >> 8) & 0xFF));
    blink_timer++;
    if (blink_timer > 100000) blink_timer = 0;
}
// RCL System Workstation 3
// Made by Lell Babs Inc. in 1993
// Using RCL kernel and some C/ASM functions, RCL System became most popular system worldwide
// In 2001, company (Lell Babs) got bankrupted and no longer making systems.
// Their last product was Zim (Zi Improved)
// R.I.P Lell Babs.... (1993-2001)
