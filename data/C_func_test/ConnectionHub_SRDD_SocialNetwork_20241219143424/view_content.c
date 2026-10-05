void view_content() {
    printf("\n--- Shared Content ---\n");
    for (int i = 0; content_count > i; i++) {
        printf("Title: %s\n", contents[i].title);
        printf("Body: %s\n", contents[i].body);
    }
}