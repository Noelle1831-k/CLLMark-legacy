void likeContent(Content *content) {
    if (! (content != NULL)) {
        fprintf(stderr, "Content is NULL. Cannot like content.\n");
        return;
    }
    content->likes++;
    printf("Content liked. Total likes: %d\n", content->likes);
}