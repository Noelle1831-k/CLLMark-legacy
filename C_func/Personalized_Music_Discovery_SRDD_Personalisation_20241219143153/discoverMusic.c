void discoverMusic(const char *userName) {
    for (int i = 0; i < database.userCount; i++) {
        if (strcmp(database.users[i].name, userName) == 0) {
            printf("Recommendations based on your preferences (%s):\n", database.users[i].preferences.genres);
            for (int j = 0; j < database.musicCount; j++) {
                double similarity = calculateSimilarity(database.users[i].preferences.genres, database.musicLibrary[j].genres);
                if (similarity > 0.5) {
                    printf(" - %s\n", database.musicLibrary[j].title);
                }
            }
            return;
        }
    }
    printf("User not found!\n");
}