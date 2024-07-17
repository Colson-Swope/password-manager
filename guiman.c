#include <ncurses.h>

// Author: Colson Swope 
// Date:   07 / 15 / 2024 
// Desc:   GUI for the user to see while the program is doing stuff

void clear_screen() {

    clear(); 

}

void display_menu(int pos) {

    //clear(); 

    if (pos == 0) {
        
        clear(); 

        printw("Password Manager\n\n"); 
        printw(">Add New\n");
        printw(" Search\n\n"); 

        return; 

    }

    if (pos == 1) {

        clear(); 
     
        printw("Password Manager\n\n"); 
        printw(" Add New\n");
        printw(">Search\n\n"); 

        return; 

    }

    refresh(); 

}

void add_new_password_menu(int step) {

    if (step == 0) {
        printw("Account name: "); 
        refresh(); 
    } 

    if (step == 1) {
        printw("Account email address: "); 
        refresh(); 
    }

    if (step == 2) {
        printw("Account password: "); 
        refresh(); 
    }

    refresh(); 

    return; 

}