void add_user_to_store(User* user) {
    if (user_count >= MAX_USERS) {
        printf("Cannot add more users. Data store is full.\n");
        return;
    }
    users[user_count++] = user; 
}