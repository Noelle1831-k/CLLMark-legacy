int main() {
    Database *db = createDatabase();
    User *user1 = createUser("Alice", "alice@example.com");
    User *user2 = createUser("Bob", "bob@example.com");
    addUser(db, user1);
    addUser(db, user2);
    Event *event1 = createEvent("Tech Meetup", "2023-11-15", "18:00", "Tech Park", "Technology");
    Event *event2 = createEvent("Gaming Night", "2023-12-10", "20:00", "Arcade Arena", "Gaming");
    addEvent(db, event1);
    addEvent(db, event2);
    joinEvent(user1, event1);
    joinEvent(user2, event1);
    joinEvent(user2, event2);
    sendMessage(user1, "Looking forward to the Tech Meetup!");
    sendMessage(user2, "Can't wait for the Gaming Night!");
    displayUserEvents(user1);
    displayUserEvents(user2);
    displayEventParticipants(event1);
    displayEventParticipants(event2);
    freeDatabase(db);
    return 0;
}