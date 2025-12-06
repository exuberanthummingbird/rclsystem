#include "keyboard.h"
#include "vga.h"
#include "string.h"

char buf[128];
int len = 0;

void terminal_run(void) {
    newline();
    printstr("> ");
    while (1) {
        char c = keyboard_getchar();
        if (!c) continue;

        if (c == '\n') {
            buf[len] = 0;

            if (strcmp(buf, "help") == 0) {
		newline();
                printstr("help - nooocord nooooo help help noooo");
		newline();
		printstr("available commands:");
		newline();
		printstr("rclfetch - Environment information");
		newline();
		printstr("linux - Very important thing.");
	    } else if (strcmp(buf, "nutella") == 0) {
		newline();
		printstr("alexey samoedov velikiy nutella king");
            } else if (strcmp(buf, "linux") == 0) {
				newline();
    			printstr("     ^     ");
    			newline();
    			printstr("____/_\\____");
    newline();
    printstr("\\  /   \\  /");
    newline();
    printstr(" \\/     \\/ ");
    newline();
    printstr(" /\\     /\\ ");
    newline();
    printstr("/__\\___/__\\ ");
    newline();
    printstr("    \\ /    ");
    newline();
    printstr("     -     ");
    newline();
			}
	      else if (strcmp(buf, "rclfetch") == 0) {
	      	newline();
		printstr("RCL System version 09_27_2025");
		newline();
		printstr("libstacking version 0.5.3-r3");
		newline();
		printstr("libtesling not installed");
		newline();
		printstr("CPU: Necropentium i586");
		newline();
		printstr("GPU: Generic NecroVGA 640x480");
		newline();
		printstr("Environment: Gqqd");
	      }
	    else {
		newline();
                printstr("Unknown command. Fatal stacking error. BAD ENV OPCODE 0xF");
            }
	    newline();
            len = 0;
            printstr("> ");
        } else if (c == '\b') {
	    if (len > 0) {
		len--;
		cursor -= 2;
		putchar(' ');
		cursor -= 2;
	    }
	} else {
            if (len < 127) buf[len++] = c;
            putchar(c);
        }
    }
}
