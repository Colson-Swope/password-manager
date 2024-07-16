#include <ncurses.h>

// Author: Colson Swope 
// Date:   07 / 15 / 2024 
// Desc:   GUI for the user to see while the program is doing stuff

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

void add_new_password_menu() {

    clear(); 

    // future note: I do not want these variables in the GUI portion of this program
    // find a different solution for handling this logic 
    char account_name[100]; 
    char account_email[100]; 
    char account_password[100]; 

    printw("Account name: "); 
    refresh(); 
    getstr(account_name); 

    printw("Account email address: "); 
    refresh(); 
    getstr(account_email); 

    printw("Account password: "); 
    refresh(); 
    getstr(account_password); 

    refresh(); 

    return; 

}