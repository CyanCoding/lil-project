#include <stdio.h>

#define VGA_ADDRESS 0xB8000   /* video memory begins here. */

/* VGA provides support for 16 colors */
#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHT_GREY		7
#define DARK_GREY		8
#define LIGHT_BLUE		9
#define LIGHT_GREEN		10
#define LIGHT_CYAN		11
#define LIGHT_RED		12
#define LIGHT_MAGENTA	13
#define YELLOW			14
#define WHITE			15

unsigned short *terminal_buffer;
unsigned int vga_index = 0;

void clear_screen() {
	int index = 0;
	/* there are 25 lines each of 80 columns;
	each element takes 2 bytes */
	while (index < 80 * 25 * 2) {
		terminal_buffer[index] = ' ';
		index += 2;
	}
}
void print(char *str, unsigned char color) {
	int index = 0;
	while (str[index]) {
		terminal_buffer[vga_index] = (unsigned short)str[index]|(unsigned short)color << 8;
		index++;
		vga_index++;
	}
}

char* to_string(unsigned int num) {
	char str[10];
	sprintf(str, "%d", num);

	return str;
}

void println(char *str, unsigned char color) {
	print(to_string(sizeof((str))), color);
	vga_index += 80;
}

int main() {
	terminal_buffer = (unsigned short *)VGA_ADDRESS;

	clear_screen();
	println("Hello world!", WHITE);

	println("Welcome to Cam's 'lil project'!", WHITE);
//    println("This is a test operating system.", WHITE);
//	println("", WHITE);
//	println("Please choose an option below", WHITE);
//	println("", WHITE);
//	println("1. Hangman", WHITE);
//	println("", WHITE);
//	print("Please enter the number of your choice > ", WHITE);
	return 0;
}
