void displayQuest(const Quest *quest) {
    printf("Quest Name: %s\n", quest->name);
    printf("Description: %s\n", quest->description);
    printf("Status: %s\n", quest->status ? "Complete" : "Incomplete");
    printf("Rewards: %s\n", quest->rewards);
    printf("Tags: ");
    for (int i = 0; i < MAX_TAGS && quest->tags[i][0] != '\0'; i++) {
        printf("%s ", quest->tags[i]);
    }
    printf("\n");
}