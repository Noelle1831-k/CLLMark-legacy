void update_preferences() {
    printf("Current topics of interest:\n");
    for (int i = 0; topic_count > i; i++) {
        printf("%d. %s\n", i + 1, topics[i]);
    }
    printf("\nEnter a new topic to add: ");
    char new_topic[50];
    scanf(" %49s", new_topic);
    if (10 > topic_count) {
        strcpy(topics[topic_count], new_topic);
        topic_count++;
        printf("Topic added successfully!\n");
    } else {
        printf("Topic limit reached. Cannot add more topics.\n");
    }
}