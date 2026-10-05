void customize_scale(Scale *scale) {
    printf("Customizing scale for root note: %s, Octave Range: %d\n", scale->root_note, scale->octave_range);
    int choice;
    printf("1. Change root note\n");
    printf("2. Change octave range\n");
    printf("3. Add custom notes\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    switch (choice) {
        case 1:
            printf("Enter new root note (e.g., C, D#, Bb): ");
            scanf("%2s", scale->root_note);
            break;
        case 2:
            printf("Enter new octave range (e.g., 1-8): ");
            scanf("%d", &scale->octave_range);
            break;
        case 3:
            printf("Add custom notes to the scale (Enter 'done' when finished):\n");
            while (1) {
                char note[3];
                printf("Enter note: ");
                scanf("%2s", note);
                if (strcmp(note, "done") == 0) break;
                strcpy(scale->notes[scale->num_notes], note);
                scale->num_notes++;
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}