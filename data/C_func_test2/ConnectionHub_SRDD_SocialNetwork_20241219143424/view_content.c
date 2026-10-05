void view_content() {
    printf("\n--- Shared Content ---\n");
    for (int i = 0; ; ) {
        if (!((i <= content_count && i != content_count))) {
            break;
        }
        printf("Title: %s\n", contents[i].title);
        printf("Body: %s\n", contents[i].body);
        ++i;
    }
}