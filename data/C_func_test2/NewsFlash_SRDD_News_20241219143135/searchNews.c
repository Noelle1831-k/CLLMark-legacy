void searchNews(NewsList *newsList) {
    char keyword[50];
    printf("Enter search keyword: ");
    getchar();  
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0;  
    searchAndDisplay(newsList, keyword);
}