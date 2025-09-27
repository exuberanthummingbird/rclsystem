#include "libs/keyboard.h"
#include "libs/vga.h"
#include "libs/terminal.h"

void faka(void) {
    clearscreen();
    printstr("Welcome to RCL System by Exuberant Hummingbird; an operating system forked from unfunny and cringe PoroshenkOS by fakadantiy");
    terminal_run();
}
