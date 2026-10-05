void searchUser(sqlite3 *db, const char *industry) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT NAME FROM USERS WHERE INDUSTRY = ?;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        return;
    }
    sqlite3_bind_text(stmt, 1, industry, -1, SQLITE_STATIC);
    printf("Searching for professionals in %s...\n", industry);
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        printf("Found professional: %s\n", sqlite3_column_text(stmt, 0));
    }
    sqlite3_finalize(stmt);
}