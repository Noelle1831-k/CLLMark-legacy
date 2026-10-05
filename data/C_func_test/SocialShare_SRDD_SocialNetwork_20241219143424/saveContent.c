void saveContent(Content *content) {
    if (content == NULL) {
        fprintf(stderr, "Content is NULL. Cannot save content.\n");
        return;
    }
    printf("Content '%s' saved for later.\n", content->title);
}