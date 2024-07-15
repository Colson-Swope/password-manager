#include <ncurses.h> 

// Author: Colson Swope 
// Date:   07 / 15 / 2024 
// Desc:   displays client logic on screen 

void program_start() {

    printf("\n\tPassword Manager\n\n"); 
    printf("\t  Add New\n");
    printf("\t  Search\n\n"); 

}

void start_cursor_position(int pos) {

    //clear(); 

    if (pos == 0) {

        printf("\n\tPassword Manager\n\n"); 
        printf("\t >Add New\n");
        printf("\t  Search\n\n"); 

    }

    if (pos == 1) {

        printf("\n\tPassword Manager\n\n"); 
        printf("\t  Add New\n");
        printf("\t >Search\n\n"); 

    }

    refresh(); 

}