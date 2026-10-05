int main() {
    MeetupManager meetupManager;
    Messaging messaging;
    User user1("Alice", "alice@example.com");
    User user2("Bob", "bob@example.com");
    User user3("Charlie", "charlie@example.com");
    Event event1("Tech Talk", "2023-11-01", "10:00", "Tech Hub", {"Technology", "Networking"});
    Event event2("Art Workshop", "2023-11-05", "14:00", "Art Center", {"Art", "Creativity"});
    Event event3("Cooking Class", "2023-11-10", "18:00", "Culinary School", {"Cooking", "Food"});
    meetupManager.addEvent(event1);
    meetupManager.addEvent(event2);
    meetupManager.addEvent(event3);
    user1.joinEvent(event1);
    user2.joinEvent(event2);
    user3.joinEvent(event3);
    messaging.sendMessage(user1, user2, "Looking forward to the Tech Talk!");
    messaging.sendMessage(user2, user3, "Excited about the Art Workshop!");
    messaging.sendMessage(user3, user1, "Can't wait for the Cooking Class!");
    meetupManager.displayEvents();
    user1.displayJoinedEvents();
    user2.displayJoinedEvents();
    user3.displayJoinedEvents();
    return 0;
}