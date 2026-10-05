void saveUserData() {
    printf("Saving user data...\n");
    writeFile("user_data.txt", &currentUser, sizeof(User));
    printf("User data saved: %s, %d, %s\n", currentUser.name, currentUser.age, currentUser.language);
}