#include "libs/keyboard.h"
#include "libs/vga.h"
#include "libs/terminal.h"

void faka(void) {
    clearscreen();
    printstr("Welcome to RCL System by NSA of RCL");
    terminal_run();
}
