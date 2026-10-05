void addComment(CommentManager *cm, const char *fileName, const char *comment) {
    if (cm->commentCount < 100) {
        strcpy(cm->comments[cm->commentCount], comment);
        cm->commentCount++;
        printf("Added comment to %s: %s\n", fileName, comment);
    }
}