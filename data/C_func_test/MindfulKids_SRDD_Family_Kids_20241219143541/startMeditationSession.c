void startMeditationSession() {
    printf("\n=== Guided Meditation ===\n");
    int sessionChoice;
    printf("Select a meditation session:\n");
    printf("1. Peaceful Beach\n");
    printf("2. Serene Forest\n");
    printf("3. Cosmic Journey\n");
    printf("Enter your choice (1-3): ");
    sessionChoice = getValidatedInput(1, 3);
    switch (sessionChoice) {
        case 1:
            printf("Starting 'Peaceful Beach' session...\n");
            printf("Imagine the sound of waves gently lapping at the shore...\n");
            sleep(3);
            break;
        case 2:
            printf("Starting 'Serene Forest' session...\n");
            printf("Picture the rustling leaves and chirping birds...\n");
            sleep(3);
            break;
        case 3:
            printf("Starting 'Cosmic Journey' session...\n");
            printf("Visualize floating among the stars in a calm, quiet universe...\n");
            sleep(3);
            break;
    }
    printf("Take a deep breath... Hold it for 4 seconds... and exhale slowly.\n");
    sleep(4);
    printf("Feel your body relaxing with every breath you take...\n");
    sleep(5);
    printf("Great job completing this session! Keep up the good work.\n");
}