int main() {
    UserInterface ui;
    FeedbackManager manager;
    bool running = true;
    while (running) {
        ui.showMenu();
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                manager.addFeedback(ui.getFeedbackInput());
                break;
            case 2:
                manager.displayAllFeedback();
                break;
            case 3:
                manager.categorizeFeedback();
                break;
            case 4:
                manager.trackFeedback();
                break;
            case 5:
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}