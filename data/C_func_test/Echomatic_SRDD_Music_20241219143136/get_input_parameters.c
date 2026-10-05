void get_input_parameters(char *input_file, char *output_file, float *delay, float *strength) {
    printf("Enter the input audio file path: ");
    scanf("%s", input_file);
    printf("Enter the output audio file path: ");
    scanf("%s", output_file);
    printf("Enter the delay (in seconds) for the echo effect: ");
    scanf("%f", delay);
    printf("Enter the strength of the echo effect (0.0 - 1.0): ");
    scanf("%f", strength);
}