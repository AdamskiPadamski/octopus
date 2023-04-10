#ifndef OCTOPUS_DRIVERS_SCREEN_H
#define OCTOPUS_DRIVERS_SCREEN_H

int get_screen_offset(int column, int row);

int get_cursor();

int handle_scrolling(int offset);

void set_cursor(int offset);

void print_char(char character, int column, int row, char attribute_byte);

void clear_screen();

#endif
