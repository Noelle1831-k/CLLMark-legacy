void import_audio() {
    char file_path[256];
    printf("Enter the path to the audio file: ");
    scanf("%s", file_path);
    if (track_count < MAX_TRACKS) {
        loaded_tracks[track_count] = import_audio_file(file_path);
        if (loaded_tracks[track_count].samples != NULL) {
            printf("Audio imported successfully: %s\n", file_path);
            track_count++;
        } else {
            printf("Failed to import audio.\n");
        }
    } else {
        printf("Maximum track limit reached.\n");
    }
}