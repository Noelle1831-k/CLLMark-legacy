void addPreferences(const char *userName, const UserPreferences *preferences) {
    strncpy(database.users[database.userCount].name, userName, MAX_NAME_LEN);
    strncpy(database.users[database.userCount].preferences.genres, preferences->genres, MAX_GENRES_LEN);
    database.userCount++;
}