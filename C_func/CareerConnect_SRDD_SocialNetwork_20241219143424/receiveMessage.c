void receiveMessage(sqlite3 *db, User *receiver) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT SENDER, MESSAGE FROM MESSAGES WHERE RECEIVER = ?;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        return;
    }
    sqlite3_bind_text(stmt, 1, receiver->name, -1, SQLITE_STATIC);
    printf("%s received messages:\n", receiver->name);
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        printf("From %s: %s\n", sqlite3_column_text(stmt, 0), sqlite3_column_text(stmt, 1));
    }
    sqlite3_finalize(stmt);
}