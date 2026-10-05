int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <tempo_factor>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float tempo_factor = atof(argv[3]);
    if (tempo_factor <= 0) {
        fprintf(stderr, "Error: Tempo factor must be greater than 0.\n");
        return EXIT_FAILURE;
    }
    float *audio_data = NULL;
    int data_size = 0;
    if (load_audio_file(input_file, &audio_data, &data_size) != 0) {
        fprintf(stderr, "Error: Failed to load audio file %s\n", input_file);
        return EXIT_FAILURE;
    }
    if (adjust_tempo(audio_data, data_size, tempo_factor) != 0) {
        fprintf(stderr, "Error: Failed to adjust tempo for audio file %s\n", input_file);
        free(audio_data);
        return EXIT_FAILURE;
    }
    if (save_audio_file(output_file, audio_data, data_size) != 0) {
        fprintf(stderr, "Error: Failed to save audio file %s\n", output_file);
        free(audio_data);
        return EXIT_FAILURE;
    }
    free(audio_data);
    printf("Audio file successfully processed and saved as %s\n", output_file);
    return EXIT_SUCCESS;
}