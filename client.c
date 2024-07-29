#include "guiman.c"
#include "dbmanager.c"
 

int main() {

    // main menu vars 
    int cursor_value;
    int pos = 0; 

    // add new password vars 
    char account_name[100]; 
    char account_email[100]; 
    char account_password[100]; 

    // init ncurses 
    initscr();  
    // enable keypad mode for arrow key reading 
    keypad(stdscr, TRUE); 
    // turn off line buffering 
    cbreak(); 
    // do not display user input on screen 
    //noecursor_valueo();

    display_menu(0); 

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
                    clear_screen(); 
                    add_new_password_menu(0); 
                    getstr(account_name); 

                    add_new_password_menu(1); 
                    getstr(account_email); 

                    add_new_password_menu(2); 
                    getstr(account_password); 

                    new_db_entry(account_name, account_email, account_password); 

                }
                break;
        }
    }

    endwin();

    return 0; 
}