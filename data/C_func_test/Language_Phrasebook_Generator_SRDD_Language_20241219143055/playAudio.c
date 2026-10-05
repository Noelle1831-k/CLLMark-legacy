void playAudio() {
    char phrase[256];
    printf("Enter the phrase to play audio for: ");
    scanf(" %[^\n]", phrase);
    printf("Playing audio pronunciation for: %s\n", phrase);
    printf("Audio playback completed.\n");
}