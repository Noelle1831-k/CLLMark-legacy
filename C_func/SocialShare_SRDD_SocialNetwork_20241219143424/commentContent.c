void commentContent(Content *content, const char *comment) {
    if (content == NULL) {
        fprintf(stderr, "Content is NULL. Cannot comment on content.\n");
        return;
    }
    printf("Comment on '%s': %s\n", content->title, comment);
}