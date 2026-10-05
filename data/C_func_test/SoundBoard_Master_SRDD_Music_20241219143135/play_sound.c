void play_sound(char* filepath) {
    if (PlaySound(filepath, NULL, SND_FILENAME | SND_ASYNC)) {
        printf("\nSuccessfully playing sound file: %s\n", filepath);
    } else {
        printf("\nFailed to play sound file: %s\n", filepath);
    }
}