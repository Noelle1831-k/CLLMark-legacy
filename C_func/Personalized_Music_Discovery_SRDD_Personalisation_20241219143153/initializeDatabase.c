void initializeDatabase() {
    database.userCount = 0;
    database.musicCount = 0;
    strncpy(database.musicLibrary[0].title, "Song A", MAX_MUSIC_TITLE_LEN);
    strncpy(database.musicLibrary[0].genres, "rock,pop", MAX_GENRES_LEN);
    database.musicCount++;
    strncpy(database.musicLibrary[1].title, "Song B", MAX_MUSIC_TITLE_LEN);
    strncpy(database.musicLibrary[1].genres, "jazz,blues", MAX_GENRES_LEN);
    database.musicCount++;
}