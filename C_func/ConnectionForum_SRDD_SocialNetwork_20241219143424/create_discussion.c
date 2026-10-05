void create_discussion() {
    if (discussion_count >= 100) {
        printf("Discussion limit reached. Cannot create more discussions.\n");
        return;
    }
    Discussion new_discussion;
    new_discussion.id = discussion_count + 1;
    new_discussion.comment_count = 0;
    printf("Enter discussion topic: ");
    scanf("%s", new_discussion.topic);
    discussions[discussion_count++] = new_discussion;
    printf("Discussion created successfully with ID: %d\n", new_discussion.id);
}