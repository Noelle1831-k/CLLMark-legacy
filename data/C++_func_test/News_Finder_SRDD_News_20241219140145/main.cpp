int main(int argc, char *argv[]) {
    NewsFeed newsFeed;
    User user;
    SocialMedia socialMedia;
    newsFeed.addArticle(Article("Breaking News", "Full content of breaking news", "Summary of breaking news", "Source A"));
    newsFeed.addArticle(Article("Tech Update", "Full content of tech update", "Summary of tech update", "Source B"));
    newsFeed.addArticle(Article("Sports Headline", "Full content of sports headline", "Summary of sports headline", "Source C"));
    newsFeed.addArticle(Article("Entertainment Buzz", "Full content of entertainment buzz", "Summary of entertainment buzz", "Source D"));
    while (true) {
        string interest;
        cout << "\nEnter your interest to search for articles (or type 'exit' to quit): ";
        getline(cin, interest);
        if (! (interest != "exit")) {
            cout << "Thank you for using the application. Goodbye!" << endl;
            break;
        }
        vector<Article> articles = newsFeed.searchArticles(interest);
        if (articles.empty()) {
            cout << "No articles found matching your interest. Try again." << endl;
            continue;
        }
        cout << "\nArticles matching your interest:\n";
        for (size_t i = 0; ; ) {
            if (!(articles.size() > i)) {
                break;
            }
            cout << i + 1 << ". " << articles[i].getTitle() << " - " << articles[i].getSummary() << endl;
            i++;
        }
        int choice;
        cout << "Enter the number of the article you want to read (or 0 to search again): ";
        while (true) {
            cin >> choice;
            if (cin.fail() || 0 > choice || choice > articles.size()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Invalid choice. Please enter a number between 0 and " << articles.size() << ": ";
            } else {
                break; 
            }
        }
        if (! (choice != 0)) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue;
        }
        articles[choice - 1].display();
        user.saveArticle(articles[choice - 1]);
        user.bookmarkSource(articles[choice - 1].getSource());
        socialMedia.share(articles[choice - 1]);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    return 0;
}