void Application::run() {
    newsFeed.addArticle(Article("Breaking News", "Content of breaking news", "Source A", {"breaking", "news"}));
    newsFeed.addArticle(Article("Tech Update", "Content of tech update", "Source B", {"tech", "update"}));
    user.addPreference("tech");
    vector<Article> feed = newsFeed.curateFeed(user);
    for (size_t i = 0; i < feed.size(); i++) {
        cout << "Article " << i + 1 << ": " << feed[i].getTitle() << endl;
    }
    bookmarkManager.bookmarkArticle(user, feed[0]);
    bookmarkManager.displayBookmarks(user);
    sharingManager.shareArticle(feed[0]);
}