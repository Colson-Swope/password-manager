#include <stdio.h> 
#include <stdbool.h> 

#include "guiman.c"

int main() {

    int cursor_value = 0;
    int = key; 

    // init ncurses 
    initscr();  
    // enable keypad mode for arrow key reading 
    keypad(stdscr, TRUE); 
    // turn off line buffering 
    cbreak(); 
    // do not display user input on screen 
    noecho();  

    program_start();

    while (true) {

        key = getch();

        switch (key) {
            case KEY_UP:
                if (cursor_value > 0) cursor_value--;
                break;
            case KEY_DOWN:
                if (cursor_value < 1) cursor_value++;
                break;
            case 27: // ESC key ascii value 
                // kills ncurses
                endwin();  
                return 0;  
            default:
                break;
        }

        start_cursor_position(cursor_value);

    }
}