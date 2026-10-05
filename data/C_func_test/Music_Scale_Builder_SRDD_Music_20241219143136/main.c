int main() {
    int choice;
    char root_note[3];
    int octave_range;
    Scale scale;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Enter root note (e.g., C, D#, Bb): ");
                scanf("%2s", root_note);
                printf("Enter octave range (e.g., 1-8): ");
                scanf("%d", &octave_range);
                scale = create_scale(root_note, octave_range);
                printf("Scale created successfully!\n");
                break;
            case 2:
                printf("Customizing scale...\n");
                customize_scale(&scale);
                break;
            case 3:
                printf("Visualizing scale...\n");
                visualize_scale(scale);
                break;
            case 4:
                printf("Playing scale...\n");
                play_scale(scale);
                break;
            case 5:
                printf("Learning about music theory...\n");
                display_music_theory();
                break;
            case 6:
                printf("Exiting application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}