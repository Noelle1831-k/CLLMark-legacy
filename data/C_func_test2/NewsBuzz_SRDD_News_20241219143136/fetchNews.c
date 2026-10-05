int fetchNews(NewsFetcher *fetcher, char articles[100][1024]) {
    strcpy(articles[0], "Breaking News: Market hits all-time high.");
    strcpy(articles[1], "Sports Update: Local team wins championship.");
    strcpy(articles[2], "Technology Alert: New AI breakthrough announced.");
    return 3;  
}