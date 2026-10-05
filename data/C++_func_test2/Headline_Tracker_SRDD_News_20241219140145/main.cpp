int main() {
    NewsManager newsManager;
    UIHandler uiHandler(newsManager);
    cout << "Welcome to the Real-Time News Tracker!" << endl;
    while (true) {
        uiHandler.promptUserAction();
        newsManager.updateHeadlines();
        uiHandler.displayHeadlines();
    }
    return 0;
}