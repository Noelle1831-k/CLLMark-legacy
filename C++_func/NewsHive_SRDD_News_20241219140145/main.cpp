int main() {
    NewsManager newsManager;
    UserPreferences userPreferences;
    vector<Article> savedArticles;
    userPreferences.loadPreferences();
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                vector<Article> news = newsManager.fetchNews();
                for (int i = 0; i < news.size(); i++) {
                    cout << i + 1 << ". ";
                    news[i].displayArticle();
                }
                break;
            }
            case 2: {
                string category;
                cout << "Enter category: ";
                cin >> category;
                vector<Article> filteredNews = newsManager.filterNewsByCategory(category);
                for (int i = 0; i < filteredNews.size(); i++) {
                    cout << i + 1 << ". ";
                    filteredNews[i].displayArticle();
                }
                break;
            }
            case 3: {
                userPreferences.updatePreferences();
                break;
            }
            case 4: {
                if (savedArticles.size() == 0) {
                    cout << "No saved articles." << endl;
                } else {
                    for (int i = 0; i < savedArticles.size(); i++) {
                        cout << i + 1 << ". ";
                        savedArticles[i].displayArticle();
                    }
                }
                break;
            }
            case 5: {
                if (savedArticles.size() < 5) {
                    string articleTitle;
                    cout << "Enter the title of the article you want to save for later: ";
                    cin.ignore();
                    getline(cin, articleTitle);
                    Article article(articleTitle, "Content Placeholder", "Source Placeholder");
                    savedArticles.push_back(article);
                    article.saveForLater();
                } else {
                    cout << "You can save only up to 5 articles at a time." << endl;
                }
                break;
            }
            case 6: {
                string articleTitle;
                cout << "Enter the title of the article you want to share: ";
                cin.ignore();
                getline(cin, articleTitle);
                Article article(articleTitle, "Content Placeholder", "Source Placeholder");
                article.shareArticle();
                break;
            }
            case 7: {
                string source;
                cout << "Enter the source of the article you want to bookmark: ";
                cin.ignore();
                getline(cin, source);
                Article article("Title Placeholder", "Content Placeholder", source);
                article.bookmarkSource();
                break;
            }
            case 8:
                cout << "Exiting NewsHive. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);
    return 0;
}