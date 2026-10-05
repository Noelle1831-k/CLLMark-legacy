void startMindfulActivity() {
    printf("\n=== Mindful Activities ===\n");
    printf("Choose an activity:\n");
    printf("1. Coloring Activity\n");
    printf("2. Journaling Prompt\n");
    printf("3. Drawing Prompt\n");
    printf("Select an activity (1-3): ");
    int choice = getValidatedInput(1, 3);
    switch (choice) {
        case 1:
            printf("Imagine coloring a beautiful mandala. Choose your favorite colors and let your imagination run wild!\n");
            break;
        case 2:
            printf("Journaling Prompt: Write about a moment today that made you smile.\n");
            break;
        case 3:
            printf("Drawing Prompt: Sketch something that represents happiness to you.\n");
            break;
        default:
            printf("Invalid choice. Returning to main menu.\n");
    }
}