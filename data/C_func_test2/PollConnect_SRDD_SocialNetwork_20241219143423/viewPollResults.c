void viewPollResults() {
    browsePolls();
    int choice;
    printf("Select a poll to view results: ");
    scanf("%d", &choice);
    Poll poll = getPoll(choice - 1);
    time_t now = time(NULL);
    if (difftime(poll.endTime, now) > 0) {
        printf("Poll: %s\n", poll.title);
        for (int i = 0; i < 5 && strlen(poll.options[i]) > 0; i++) {
            printf("%s: %d votes\n", poll.options[i], poll.votes[i]);
        }
    } else {
        printf("This poll has ended. Here are the final results:\n");
        for (int i = 0; i < 5 && strlen(poll.options[i]) > 0; i++) {
            printf("%s: %d votes\n", poll.options[i], poll.votes[i]);
        }
    }
}