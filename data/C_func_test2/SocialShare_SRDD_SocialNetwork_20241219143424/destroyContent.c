void destroyContent(Content *content) {
    if (content != NULL) {
        printf("Destroying content: %s\n", content->title);
        free(content);
    }
}