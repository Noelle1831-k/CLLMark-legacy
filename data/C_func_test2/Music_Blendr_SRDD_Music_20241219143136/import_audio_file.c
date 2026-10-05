Track import_audio_file(const char *file_path) {
    Track track;
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", file_path);
        track.samples = NULL;
        return track;
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    track.samples = (float *)malloc(file_size);
    fread(track.samples, sizeof(float), file_size / sizeof(float), file);
    fclose(file);
    track.track_name = strdup(file_path);
    track.duration = (file_size / sizeof(float)) / 44100; 
    track.sample_rate = 44100;
    return track;
}