MentorshipRequest* requestMentorship(sqlite3 *db, User *requester, User *mentor) {
    char *errMsg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO MENTORSHIP_REQUESTS (REQUESTER, MENTOR, STATUS) VALUES ('%s', '%s', %d);",
             requester->name, mentor->name, 0);
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Mentorship request from %s to %s created.\n", requester->name, mentor->name);
    }
    MentorshipRequest *newRequest = (MentorshipRequest*)malloc(sizeof(MentorshipRequest));
    newRequest->requester = requester;
    newRequest->mentor = mentor;
    newRequest->status = 0;
    return newRequest;
}