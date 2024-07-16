#include <stdio.h> 

#include "guiman.c"

int main() {

    int cursor_value;
    int pos = 0; 

    // init ncurses 
    initscr();  
    // enable keypad mode for arrow key reading 
    keypad(stdscr, TRUE); 
    // turn off line buffering 
    cbreak(); 
    // do not display user input on screen 
    //noecursor_valueo();

    while((cursor_value = getch()) != 'q') {

        switch(cursor_value) {
            case KEY_UP:
                pos = 0;
                              
                display_menu(pos);
                break; 

            case KEY_DOWN:
                pos = 1;
             
                display_menu(pos);
                break;

            default:

                // user wants to add a new password 
                if (pos == 0 || cursor_value == KEY_ENTER) {

                    add_new_password_menu(); 

                }
                break;
        }
    }

    endwin();

    return 0; 
}