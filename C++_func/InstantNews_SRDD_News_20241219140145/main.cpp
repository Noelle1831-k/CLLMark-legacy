int main() {
    cout << "Welcome to InstantNews - Real-Time Breaking News Application!" << endl;
    NewsManager newsManager;
    UserInterface userInterface;
    BookmarkManager bookmarkManager;
    ShareManager shareManager;
    while (true) {
        int userChoice;
        cout << "\nMain Menu:\n1. View Latest News\n2. View Bookmarked Articles\n3. Exit\nChoose an option: ";
        cin >> userChoice;
        if (userChoice == 1) {
            auto newsHeadlines = newsManager.fetchLatestNews();
            userInterface.displayHeadlines(newsHeadlines);
            cout << "\nSelect an article to read (Enter 0 to go back): ";
            int articleChoice;
            cin >> articleChoice;
            if (articleChoice > 0 && articleChoice <= newsHeadlines.size()) {
                string article = newsManager.getArticle(articleChoice - 1);
                userInterface.displayArticle(article);
                cout << "\nArticle Options:\n1. Bookmark Article\n2. Share Article\n3. Go Back\nChoose an option: ";
                int actionChoice;
                cin >> actionChoice;
                if (actionChoice == 1) {
                    bookmarkManager.addBookmark(article);
                } else if (actionChoice == 2) {
                    shareManager.shareArticle(article);
                }
            }
        } else if (userChoice == 2) {
            auto bookmarks = bookmarkManager.getBookmarks();
            if (bookmarks.empty()) {
                cout << "\nNo bookmarked articles yet.\n";
            } else {
                userInterface.displayBookmarkedArticles(bookmarks);
            }
        } else if (userChoice == 3) {
            cout << "Thank you for using InstantNews. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}