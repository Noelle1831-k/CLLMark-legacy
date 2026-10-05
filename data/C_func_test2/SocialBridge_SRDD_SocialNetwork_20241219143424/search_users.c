void search_users() {
    char *keyword = (char*)malloc(sizeof(char) * 50);
    printf("Enter keyword to search: ");
    scanf("%s", keyword);
    retrieve_users(keyword);
}