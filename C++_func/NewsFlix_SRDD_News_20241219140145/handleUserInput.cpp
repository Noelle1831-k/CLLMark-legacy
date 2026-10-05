void NewsApp::handleUserInput(int choice) {
    switch (choice) {
        case 1:
            recommendationEngine.displayRecommendations(user);
            break;
        case 2:
            searchEngine.searchArticles();
            break;
        case 3:
            user.viewSavedArticles();
            break;
        case 4:
            shareManager.shareArticle();
            break;
        case 0:
            cout << "Exiting application..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}