void share_content() {
    printf("Enter content title: ");
    scanf(" %[^\n]s", contents[content_count].title);
    printf("Enter content body: ");
    scanf(" %[^\n]s", contents[content_count].body);
    content_count++;
    printf("Content shared successfully!\n");
}