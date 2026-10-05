int main() {
    char input_file[256];
    char output_file[256];
    float tempo_factor = 1.0;
    int choice;
    AudioData *audio_data = NULL;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter the path to the music file: ");
                scanf("%s", input_file);
                audio_data = load_audio_file(input_file);
                if (audio_data) {
                    printf("Music file loaded successfully.\n");
                } else {
                    printf("Failed to load music file. Please check the file path and format.\n");
                }
                break;
            case 2:
                if (!audio_data) {
                    printf("No music file loaded. Please load a file first.\n");
                    break;
                }
                printf("Enter the tempo adjustment factor (e.g., 1.5 for 150%% speed): ");
                if (scanf("%f", &tempo_factor) != 1 || tempo_factor <= 0) {
                    printf("Invalid tempo factor. Please enter a positive number.\n");
                    while (getchar() != '\n'); 
                    break;
                }
                adjust_tempo(audio_data, tempo_factor);
                printf("Tempo adjusted successfully.\n");
                break;
            case 3:
                if (!audio_data) {
                    printf("No music file loaded. Please load a file first.\n");
                    break;
                }
                printf("Enter the path to save the adjusted file: ");
                scanf("%s", output_file);
                save_audio_file(output_file, audio_data);
                printf("File saved successfully.\n");
                break;
            case 4:
                if (!audio_data) {
                    printf("No music file loaded. Please load a file first.\n");
                    break;
                }
                process_audio(audio_data);
                printf("Audio normalized successfully.\n");
                break;
            case 5:
                printf("Exiting the application. Goodbye!\n");
                if (audio_data) {
                    free_audio_data(audio_data);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}