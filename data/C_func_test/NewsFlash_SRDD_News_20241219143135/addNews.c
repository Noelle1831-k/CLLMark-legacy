void addNews(NewsList *newsList) {
    char title[256], category[50], content[1024];
    printf("Enter the news title: ");
    getchar();  
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;  
    printf("Enter the category (e.g., Politics, Technology, etc.): ");
    fgets(category, sizeof(category), stdin);
    category[strcspn(category, "\n")] = 0;  
    printf("Enter the news content: ");
    fgets(content, sizeof(content), stdin);
    content[strcspn(content, "\n")] = 0;  
    News *news = (News*)malloc(sizeof(News));
    if (!news) {
        printf("Failed to allocate memory for news.\n");
        return;
    }
    news->title = strdup(title);
    news->category = strdup(category);
    news->content = strdup(content);
    NewsNode *newNode = (NewsNode*)malloc(sizeof(NewsNode));
    if (!newNode) {
        printf("Failed to allocate memory for news node.\n");
        free(news->title);
        free(news->category);
        free(news->content);
        free(news);
        return;
    }
    newNode->news = news;
    newNode->next = newsList->head;
    newsList->head = newNode;
    newsList->size++;
    printf("News story added successfully!\n");
}