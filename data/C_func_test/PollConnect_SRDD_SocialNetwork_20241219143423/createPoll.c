void createPoll() {
    Poll poll;
    int numOptions;
    printf("Enter Poll Title: ");
    scanf(" %[^\n]", poll.title);
    printf("Enter number of options (max 5): ");
    scanf("%d", &numOptions);
    for (int i = 0; i < numOptions; i++) {
        printf("Enter option %d: ", i + 1);
        scanf(" %[^\n]", poll.options[i]);
        poll.votes[i] = 0;
    }
    printf("Enter poll duration in minutes: ");
    int duration;
    scanf("%d", &duration);
    poll.endTime = time(NULL) + (duration * 60);
    savePoll(&poll);
    printf("Poll created successfully!\n");
}