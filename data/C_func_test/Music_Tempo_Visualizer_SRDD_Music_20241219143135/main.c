int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }
    int verbose = 0;
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            print_usage(argv[0]);
            return EXIT_SUCCESS;
        } else if (strcmp(argv[i], "--verbose") == 0) {
            verbose = 1;
        }
    }
    char *music_file = argv[1];
    if (verbose) {
        printf("Loading music file: %s\n", music_file);
    }
    AudioData *audio_data = load_music_file(music_file);
    if (!audio_data) {
        fprintf(stderr, "Error: Failed to load music file: %s\n", music_file);
        return EXIT_FAILURE;
    }
    if (verbose) {
        printf("Analyzing tempo...\n");
    }
    TempoData *tempo_data = analyze_tempo(audio_data);
    if (!tempo_data) {
        fprintf(stderr, "Error: Failed to analyze tempo.\n");
        free_audio_data(audio_data);
        return EXIT_FAILURE;
    }
    if (verbose) {
        printf("Visualizing tempo...\n");
    }
    if (!visualize_tempo(tempo_data)) {
        fprintf(stderr, "Error: Failed to visualize tempo.\n");
    }
    free_tempo_data(tempo_data);
    free_audio_data(audio_data);
    if (verbose) {
        printf("Execution completed successfully.\n");
    }
    return EXIT_SUCCESS;
}