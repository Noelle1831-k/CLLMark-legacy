int main() {
    int choice;
    char file_path[MAX_FILENAME_LENGTH];
    char manual_chords[MAX_INPUT_SIZE];
    chord_count = 0;
    while (1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("Invalid input. Please enter a valid choice.\n");
            continue;
        }
        clear_input_buffer();  
        switch (choice) {
            case 1:
                printf("Enter MIDI file path: ");
                fgets(file_path, MAX_FILENAME_LENGTH, stdin);
                file_path[strcspn(file_path, "\n")] = '\0'; 
                if (parse_midi_file(file_path)) {
                    printf("MIDI file parsed successfully.\n");
                    analyze_chords();
                    generate_charts();
                } else {
                    printf("Failed to parse MIDI file.\n");
                }
                break;
            case 2:
                printf("Enter chord progression (comma-separated, e.g., C,G,Am,F): ");
                fgets(manual_chords, MAX_INPUT_SIZE, stdin);
                manual_chords[strcspn(manual_chords, "\n")] = '\0'; 
                if (parse_manual_input(manual_chords)) {
                    analyze_chords();
                    generate_charts();
                } else {
                    printf("Invalid chord input.\n");
                }
                break;
            case 3:
                if (chord_count > 0) {
                    analyze_chords();
                } else {
                    printf("No chords to analyze. Please input a MIDI file or chord progression.\n");
                }
                break;
            case 4:
                if (chord_count > 0) {
                    generate_charts();
                } else {
                    printf("No chords to visualize. Please input a MIDI file or chord progression.\n");
                }
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}