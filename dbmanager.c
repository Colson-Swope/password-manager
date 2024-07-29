#include <sqlite3.h>
#include <stdlib.h>
#include <stdio.h> 

// for reference: https://zetcode.com/db/sqlitec/
int new_db_entry(char name[100], char email[100], char encrypted_password[100]) {

    sqlite3 *db; 
    char *err_msg = 0; 
    sqlite3_stmt *stmt;
    
    int base = sqlite3_open("db/userdata", &db); 

    if (base != SQLITE_OK) {

        fprintf(stderr, "ERROR OPENING DATABASE: %s\n", sqlite3_errmsg(db)); 
        sqlite3_close(db); 

        return 1; 
    }

    char *sql = "CREATE TABLE IF NOT EXISTS Users("
                "ID INT PRIMARY KEY NOT NULL,"
                "acct_name TEXT NOT NULL,"
                "email TEXT NOT NULL,"
                "password TEXT NOT NULL);";
    
    base = sqlite3_exec(db, sql, 0, 0, &err_msg); 

    if (base != SQLITE_OK) {
        fprintf(stderr, "SQL ERROR: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db); 

        return 1; 
    }

    sql = "INSERT INTO Users (ID, acct_name, email, password) VALUES (?, ?, ?, ?);";

    base = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (base != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    // place holder 
    int generated_id = 1;

    const char *recv_name = name; 
    const char *recv_email = email; 
    const char *recv_password = encrypted_password; 

    sqlite3_bind_int(stmt, 1, generated_id); 
    sqlite3_bind_text(stmt, 2, recv_name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, recv_email, -1, SQLITE_STATIC); 
    sqlite3_bind_text(stmt, 4, recv_password, -1, SQLITE_STATIC); 

    base = sqlite3_step(stmt); 

    if (base != SQLITE_DONE) {
        fprintf(stderr, "FAILED TO EXECUTE: %s", sqlite3_errmsg(db)); 
    }

    sqlite3_finalize(stmt); 

    sql = "SELECT * FROM Users WHERE ID = ?;"; 
    base = sqlite3_prepare_v2(db, sql, -1, &stmt, 0); 

    if (base != SQLITE_OK) {
        fprintf(stderr, "FAILED TO PREPARE STATEMENT: %s", sqlite3_errmsg(db)); 
        return 0; 
    }

    sqlite3_bind_int(stmt, 1, generated_id); 

    while ((base = sqlite3_step(stmt)) == SQLITE_ROW) {}

    if (base != SQLITE_DONE) {
        fprintf(stderr, "FAILED TO EXECUTE: %s", sqlite3_errmsg(db)); 
    }

    sqlite3_finalize(stmt);

    sqlite3_close(db); 

    return 0; 
}
