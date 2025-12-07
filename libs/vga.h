#pragma once

#define VIDMEM ((char*)0xB8000)

extern unsigned int cursor;
extern unsigned int cursor_pos;
extern unsigned int blink_timer;

void printstr(const char *str);
void putchar(char c);
void clearscreen(void);
void newline(void);
void update_cursor(void);
