User createUser(const char *username) {
    User user;
    strcpy(user.username, username);
    user.favoriteRecipesCount = 0;
    return user;
}