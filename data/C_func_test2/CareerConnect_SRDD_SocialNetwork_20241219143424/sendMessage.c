void sendMessage(sqlite3 *db, User *sender, User *receiver, const char *message) {
    char *errMsg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO MESSAGES (SENDER, RECEIVER, MESSAGE) VALUES ('%s', '%s', '%s');",
             sender->name, receiver->name, message);
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("%s sends message to %s: %s\n", sender->name, receiver->name, message);
    }
}