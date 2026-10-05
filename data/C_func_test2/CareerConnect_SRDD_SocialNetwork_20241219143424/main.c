int main() {
    sqlite3 *db;
    int rc = sqlite3_open("careerconnect.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    } else {
        printf("Opened database successfully\n");
    }
    createTables(db);
    printf("Welcome to CareerConnect!\n");
    User *user1 = createUser(db, "Alice", "Engineering", "Student");
    User *user2 = createUser(db, "Bob", "Engineering", "Professional");
    searchUser(db, "Engineering");
    MentorshipRequest *request = requestMentorship(db, user1, user2);
    respondToRequest(db, request, 1);
    sendMessage(db, user1, user2, "Hello, I would like to connect with you.");
    receiveMessage(db, user2);
    createEvent(db, "Virtual Career Fair", "Engineering");
    listEvents(db);
    sqlite3_close(db);
    return 0;
}