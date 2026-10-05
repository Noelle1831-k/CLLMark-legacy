void loadUserData() {
    printf("Loading user data...\n");
    strcpy(currentUser.name, "John Doe");
    currentUser.age = 25;
    strcpy(currentUser.language, "Spanish");
    printf("User data loaded: %s, %d, %s\n", currentUser.name, currentUser.age, currentUser.language);
}