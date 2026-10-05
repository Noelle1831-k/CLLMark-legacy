int main() {
    NewsManager newsManager;
    UserPreferences userPreferences;
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                vector<NewsArticle> curatedNews = newsManager.getCuratedNews(userPreferences);
                cout << "\nToday's News Digest:\n";
                for (size_t i = 0; i < curatedNews.size(); ++i) {
                    cout << i + 1 << ". " << curatedNews[i].getTitle() << " (" << curatedNews[i].getCategory() << ")\n";
                }
                cout << endl;
                break;
            }
            case 2: {
                cout << "Enter your preferred categories (comma-separated): ";
                string categories;
                cin.ignore();
                getline(cin, categories);
                userPreferences.updatePreferences(categories);
                cout << "Preferences updated successfully!\n";
                break;
            }
            case 3:
                cout << "Thank you for using The Daily Digest. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
    return 0;
}