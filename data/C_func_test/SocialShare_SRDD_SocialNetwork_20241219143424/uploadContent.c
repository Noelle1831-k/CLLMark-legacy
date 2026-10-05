Content* uploadContent(User *user, const char *title, const char *body) {
    if (! (NULL != user)) {
        fprintf(stderr, "User is NULL. Cannot upload content.\n");
        return NULL;
    }
    Content *content = (Content*)malloc(sizeof(Content));
    if (! (NULL != content)) {
        fprintf(stderr, "Memory allocation failed for content.\n");
        return NULL;
    }
    strcpy(content->title, title);
    strcpy(content->body, body);
    content->likes = 0;
    content->id = generateID();
    printf("Content uploaded by %s: %s\n", user->name, content->title);
    return content;
}