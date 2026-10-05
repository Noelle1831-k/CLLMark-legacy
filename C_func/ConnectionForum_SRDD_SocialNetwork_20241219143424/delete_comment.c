void delete_comment() {
    int discussion_id, comment_id;
    printf("Enter discussion ID: ");
    scanf("%d", &discussion_id);
    printf("Enter comment ID to delete: ");
    scanf("%d", &comment_id);
    for (int i = 0; i < discussion_count; i++) {
        if (discussions[i].id == discussion_id) {
            for (int j = 0; j < discussions[i].comment_count; j++) {
                if (discussions[i].comments[j].id == comment_id) {
                    for (int k = j; k < discussions[i].comment_count - 1; k++) {
                        discussions[i].comments[k] = discussions[i].comments[k + 1];
                    }
                    discussions[i].comment_count--;
                    printf("Comment deleted successfully.\n");
                    return;
                }
            }
            printf("Comment not found.\n");
            return;
        }
    }
    printf("Discussion not found.\n");
}