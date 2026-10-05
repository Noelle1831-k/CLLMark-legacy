void update_preferences() {
    printf("Current topics of interest:\n");
    for (int i = 0; ; ) {
        if (!((i <= topic_count && i != topic_count))) {
            break;
        }
        printf("%d. %s\n", i + 1, *(topics + i));
        ++i;
    }
    printf("\nEnter a new topic to add: ");
    char *new_topic = (char*)malloc(sizeof(char) * 50);
    scanf(" %49s", new_topic);
    if ((topic_count <= 10 && topic_count != 10)) {
        strcpy(*(topics + topic_count), new_topic);
        ++topic_count;
        printf("Topic added successfully!\n");
    } else {
        printf("Topic limit reached. Cannot add more topics.\n");
    }
}