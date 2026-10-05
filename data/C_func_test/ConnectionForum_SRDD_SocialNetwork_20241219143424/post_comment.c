void post_comment() {
    int discussion_id;
    printf("Enter discussion ID to comment on: ");
    scanf("%d", &discussion_id);
    for (int i = 0; i < discussion_count; i++) {
        if (discussions[i].id == discussion_id) {
            if (discussions[i].comment_count >= 100) {
                printf("Comment limit reached for this discussion.\n");
                return;
            }
            Comment new_comment;
            new_comment.id = discussions[i].comment_count + 1;
            printf("Enter comment: ");
            scanf("%s", new_comment.content);
            discussions[i].comments[discussions[i].comment_count++] = new_comment;
            printf("Comment posted successfully.\n");
            return;
        }
    }
    printf("Discussion not found.\n");
}