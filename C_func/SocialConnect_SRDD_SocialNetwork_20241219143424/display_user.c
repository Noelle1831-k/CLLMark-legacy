void display_user(const User *user) {
    if (user) {
        printf("Name: %s\n", user->name);
        printf("Interests: %s\n", user->interests);
        printf("Hobbies: %s\n", user->hobbies);
    }
}