#ifndef A_H
#define A_H

#define VIDEO_MEMORY_START_ADDRESS 0xb8000
#define MAXIMUM_ROWS 25
#define MAXIMUM_COLUMNS 80
#define WHITE_ON_BLACK 0x0f
#define SCREEN_CONTROL_REGISTER 0x3d4
#define SCREEN_DATA_REGISTER 0x3d5
#define CURSOR_LOCATION_HIGH_REGISTER 14
#define CURSOR_LOCATION_LOW_REGISTER 15

int get_screen_offset(int column, int row);

int get_cursor();

int handle_scrolling(int offset);

void set_cursor(int offset);

void print_char(char character, int column, int row, char attribute_byte);

void clear_screen();

#endif
