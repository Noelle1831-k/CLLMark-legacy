int main() {
    NewsViewer viewer;
    viewer.loadSources();
    int choice = 0;
    while (true) {
        showMainMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                viewer.displayNews();
                break;
            case 2: {
                cout << "Enter the article number to read: ";
                int index;
                cin >> index;
                viewer.readArticle(index);
                break;
            }
            case 3:
                cout << "Exiting News Viewer. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}