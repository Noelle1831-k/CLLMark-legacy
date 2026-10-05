int main(int argc, char *argv[]) {
    char *input_file = (char*)malloc(sizeof(char) * 256), *output_file = (char*)malloc(sizeof(char) * 256);
    float delay, strength;
    get_input_parameters(input_file, output_file, &delay, &strength);
    AudioData *audio_data = read_wav(input_file);
    if (!audio_data) {
        print_error("Failed to read audio file.");
        return 1;
    }
    apply_echo(audio_data, delay, strength);
    if (!write_wav(output_file, audio_data)) {
        print_error("Failed to write audio file.");
        free_safe(audio_data);
        return 1;
    }
    printf("Echo effect applied successfully!\n");
    free_safe(audio_data);
    return 0;
}