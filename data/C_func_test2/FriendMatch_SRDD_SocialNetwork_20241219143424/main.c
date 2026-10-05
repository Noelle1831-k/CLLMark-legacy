int main() {
    User *user1 = create_profile("Alice", 25, "alice@example.com");
    User *user2 = create_profile("Bob", 30, "bob@example.com");
    if (user1 == NULL || user2 == NULL) {
        fprintf(stderr, "Failed to create user profiles.\n");
        return EXIT_FAILURE;
    }
    add_interest(user1, "Reading");
    add_interest(user1, "Hiking");
    add_interest(user2, "Reading");
    add_interest(user2, "Cooking");
    match_users(user1, user2);
    send_message(user1, user2, "Hi Bob! I see you like reading too!");
    plan_activity(user1, user2, "Book Club Meeting");
    free(user1);
    free(user2);
    return EXIT_SUCCESS;
}