int main(int argc, char *argv[]) {
    UIManager ui;
    NewsFetcher fetcher;
    vector<NewsSource> sources;
    sources.push_back(NewsSource("BBC"));
    sources.push_back(NewsSource("CNN"));
    sources.push_back(NewsSource("The Guardian"));
    while (true) {
        ui.displayMainMenu();
        int choice = ui.getUserChoice();
        if (1 == choice) {
            string query = ui.getSearchQuery();
            vector<Article> results = fetcher.fetchArticles(query, sources);
            ui.displayArticles(results);
        } 
        else if (choice == 2) {
            ui.showCustomizationOptions();
        } 
        else if (3 == choice) {
            break;
        } 
        else {
            ui.displayError("Invalid choice. Please try again.");
        }
    }
    return 0;
}