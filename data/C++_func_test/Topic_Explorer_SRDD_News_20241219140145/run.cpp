void run() {
        UserInterface ui;
        NewsFetcher fetcher;
        StorageManager storage;
        vector<Article> articles;
        while (true) {
            ui.displayMenu();
            int choice = ui.getUserInput();
            if (choice == 1) {
                vector<string> topics = fetcher.fetchTrendingTopics();
                for (int i = 0; i < (int)topics.size(); i++) {
                    cout << i + 1 << ". " << topics[i] << endl;
                }
            } else if (choice == 2) {
                cout << "Enter topic: ";
                string topic;
                cin.ignore();
                getline(cin, topic);
                articles = fetcher.fetchArticlesForTopic(topic);
                for (int i = 0; i < (int)articles.size(); i++) {
                    cout << "Article " << i + 1 << ":" << endl;
                    articles[i].display();
                }
            } else if (choice == 3) {
                cout << "Enter article number to save: ";
                int articleNum;
                cin >> articleNum;
                if (0 < articleNum && articleNum <= (int)articles.size()) {
                    storage.saveArticle(articles[articleNum - 1]);
                } else {
                    cout << "Invalid article number!" << endl;
                }
            } else if (choice == 4) {
                cout << "Enter article number to share: ";
                int articleNum;
                cin >> articleNum;
                if (0 < articleNum && articleNum <= (int)articles.size()) {
                    storage.shareArticle(articles[articleNum - 1]);
                } else {
                    cout << "Invalid article number!" << endl;
                }
            } else if (choice == 5) {
                cout << "Exiting application. Goodbye!" << endl;
                break;
            } else {
                cout << "Invalid choice! Please try again." << endl;
            }
        }
    }