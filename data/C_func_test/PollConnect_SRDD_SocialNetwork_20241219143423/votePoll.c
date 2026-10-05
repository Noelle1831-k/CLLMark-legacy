void votePoll() {
    browsePolls();
    int choice, option;
    printf("Select a poll to vote: ");
    scanf("%d", &choice);
    Poll poll = getPoll(choice - 1);
    time_t now = time(NULL);
    if (difftime(poll.endTime, now) > 0) {
        printf("Poll: %s\n", poll.title);
        for (int i = 0; i < 5 && strlen(poll.options[i]) > 0; i++) {
            printf("%d. %s\n", i + 1, poll.options[i]);
        }
        printf("Choose an option: ");
        scanf("%d", &option);
        poll.votes[option - 1]++;
        savePoll(&poll);
        printf("Vote recorded successfully!\n");
    } else {
        printf("This poll has ended and cannot be voted on.\n");
    }
}