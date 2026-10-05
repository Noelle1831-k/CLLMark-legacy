int main() {
    UserPreferences userPrefs;
    NewsArticles news;
    Digest dailyDigest;
    memset(&userPrefs, 0, sizeof(UserPreferences));
    load_preferences(&userPrefs);
    load_news_data(&news);
    generate_daily_digest(&news, &userPrefs, &dailyDigest);
    display_digest(&dailyDigest);
    return 0;
}