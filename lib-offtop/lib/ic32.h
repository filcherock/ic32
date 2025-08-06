/*
==================================================================
Irion Console 32 Library
Copyright (C) 2025 filcher

To understand the library functions, study the documentation for ic32
==================================================================
*/

// Include stdint
#include <stdint.h>

// Video mode
volatile char* vga_buffer = (volatile char*)0xB8000;
static uint16_t vga_position = 0;

// Define convenient names of colors
#define VGA_COLOR 0x07
#define VGA_DARK 0x0
#define VGA_BLUE 0x1
#define VGA_GREEN 0x2
#define VGA_CYAN 0x3
#define VGA_RED 0x4
#define VGA_PURPLE 0x5
#define VGA_YELLOW 0x6
#define VGA_GREY 0x8

// Print function
void print(const char* str, int colornum) {
    while (*str) {
        if (*str == '\n') {
            vga_position += 80 - (vga_position % 80);
        } else {
            vga_buffer[vga_position * 2] = *str;
            vga_buffer[vga_position * 2 + 1] = colornum;
            vga_position++;
        }
        str++;
    }
}