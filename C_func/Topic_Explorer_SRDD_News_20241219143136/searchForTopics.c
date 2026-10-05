void searchForTopics() {
    char query[100];
    printf("Enter topic to search: ");
    scanf("%s", query);
    printf("Searching for topics related to '%s'...\n", query);
    printf("Found 3 articles related to '%s':\n", query);
    printf("1. 'Understanding %s: A Comprehensive Guide'\n", query);
    printf("2. '%s: Latest Updates and Insights'\n", query);
    printf("3. 'How %s is Shaping the Future'\n", query);
}