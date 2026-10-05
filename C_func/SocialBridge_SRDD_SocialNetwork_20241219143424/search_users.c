void search_users() {
    char keyword[50];
    printf("Enter keyword to search: ");
    scanf("%s", keyword);
    retrieve_users(keyword);
}