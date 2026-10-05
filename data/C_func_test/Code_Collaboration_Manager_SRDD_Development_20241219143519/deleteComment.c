void deleteComment(CommentManager *cm, int index) {
    if (index < cm->commentCount) {
        for (int i = index; i < cm->commentCount - 1; i++) {
            strcpy(cm->comments[i], cm->comments[i + 1]);
        }
        cm->commentCount--;
        printf("Deleted comment at index %d\n", index);
    }
}