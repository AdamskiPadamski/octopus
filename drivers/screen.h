#ifndef SCREEN_H
#define SCREEN_H

int get_screen_offset(int column, int row);

int get_cursor();

int handle_scrolling(int offset);

void set_cursor(int offset);

void print_char(char character, int column, int row, char attribute_byte);

void clear_screen();

#endif
