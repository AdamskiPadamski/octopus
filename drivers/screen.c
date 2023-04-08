#include "../kernel/low_level.h"
#include "./screen.h"

#define VIDEO_MEMORY_START_ADDRESS 0xb8000
#define MAXIMUM_ROWS 25
#define MAXIMUM_COLUMNS 80
#define WHITE_ON_BLACK 0x0f
#define SCREEN_CONTROL_REGISTER 0x3d4
#define SCREEN_DATA_REGISTER 0x3d5
#define CURSOR_LOCATION_HIGH_REGISTER 14
#define CURSOR_LOCATION_LOW_REGISTER 15

int get_screen_offset(int column, int row) {
  return (row * MAXIMUM_COLUMNS + column) * 2;
}

int get_cursor() {
  int offset = 0;

  port_byte_out(SCREEN_CONTROL_REGISTER, CURSOR_LOCATION_HIGH_REGISTER);
  offset |= (port_byte_in(SCREEN_DATA_REGISTER) << 8);

  port_byte_out(SCREEN_CONTROL_REGISTER, CURSOR_LOCATION_LOW_REGISTER);
  offset |= port_byte_in(SCREEN_DATA_REGISTER);

  return offset;
}

int handle_scrolling(int offset) {
  return offset;
}

void set_cursor(int offset) {
  port_byte_out(SCREEN_CONTROL_REGISTER, CURSOR_LOCATION_HIGH_REGISTER);
  port_byte_out(SCREEN_DATA_REGISTER, offset >> 8); 

  port_byte_out(SCREEN_CONTROL_REGISTER, CURSOR_LOCATION_LOW_REGISTER);
  port_byte_out(SCREEN_DATA_REGISTER, offset & 0xff); 
}

void print_char(char character, int column, int row, char attribute_byte) {
  unsigned char *video_memory = (unsigned char *) VIDEO_MEMORY_START_ADDRESS;

  if (!attribute_byte) {
    attribute_byte = WHITE_ON_BLACK;
  }

  int offset;

  if (column >= 0 && row >= 0) {
    offset = get_screen_offset(column, row);
  } else {
    offset = get_cursor();
  }

  if (character == '\n') {
    int rows = offset / (2 * MAXIMUM_COLUMNS);
    offset = get_screen_offset(79, rows);
  } else {
    video_memory[offset] = character;
    video_memory[offset + 1] = attribute_byte;
  }

  offset += 2;
  offset = handle_scrolling(offset);
  set_cursor(offset);
}

void clear_screen() {
  for (int i = 0; i < MAXIMUM_ROWS; i++) {
    for (int j = 0; j < MAXIMUM_ROWS; j++) {
      print_char(' ', j, i, 0);
    }
  }

  set_cursor(0);
}
