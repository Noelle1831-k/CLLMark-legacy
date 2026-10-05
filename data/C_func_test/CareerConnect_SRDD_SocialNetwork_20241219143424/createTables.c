void createTables(sqlite3 *db) {
    char *errMsg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS USERS("  \
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
                      "NAME TEXT NOT NULL," \
                      "INDUSTRY TEXT NOT NULL," \
                      "ROLE TEXT NOT NULL);";
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Table created successfully\n");
    }
}