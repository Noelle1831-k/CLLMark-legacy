void viewComments(CommentManager *cm) {
    printf("Viewing comments...\n");
    for (int i = 0; i < cm->commentCount; i++) {
        printf("Comment %d: %s\n", i + 1, cm->comments[i]);
    }
}