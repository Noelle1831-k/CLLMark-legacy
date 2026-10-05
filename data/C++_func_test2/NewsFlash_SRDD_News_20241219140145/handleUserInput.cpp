void handleUserInput() {
        int choice;
        cin >> choice;
        cin.ignore(); 
        if (choice == 1) {
            string title, content, category;
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter content: ";
            getline(cin, content);
            cout << "Enter category: ";
            getline(cin, category);
            string timestamp = getCurrentTimestamp();
            NewsArticle article(title, content, category, timestamp);
            feed.addArticleToCategory(category, article);
        } else if (choice == 2) {
            feed.displayFeed();
        } else if (choice == 3) {
            string keyword;
            cout << "Enter keyword to search: ";
            cin >> keyword;
            vector<NewsArticle> results = feed.searchArticles(keyword);
            cout << "Search Results:" << endl;
            for (size_t i = 0; i < results.size(); i++) {
                results[i].displayArticle();
            }
        } else if (choice == 4) {
            cout << "Exiting NewsFlash. Goodbye!" << endl;
            exit(0);
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }