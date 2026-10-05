void browsePolls() {
    Poll polls[50];
    int count = getPolls(polls);
    time_t now = time(NULL);
    printf("Available Polls:\n");
    for (int i = 0; i < count; i++) {
        if (difftime(polls[i].endTime, now) > 0) { 
            printf("%d. %s\n", i + 1, polls[i].title);
        }
    }
}