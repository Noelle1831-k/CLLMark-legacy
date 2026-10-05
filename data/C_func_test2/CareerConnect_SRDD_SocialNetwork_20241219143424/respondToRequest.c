void respondToRequest(sqlite3 *db, MentorshipRequest *request, int response) {
    char *errMsg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "UPDATE MENTORSHIP_REQUESTS SET STATUS = %d WHERE REQUESTER = '%s' AND MENTOR = '%s';",
             response, request->requester->name, request->mentor->name);
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        if (1 == response) {
            printf("Request accepted by %s.\n", request->mentor->name);
        } else {
            printf("Request declined by %s.\n", request->mentor->name);
        }
    }
}