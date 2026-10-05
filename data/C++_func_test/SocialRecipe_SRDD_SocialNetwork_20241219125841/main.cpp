int main() {
    User user;
    Recipe recipe;
    Community community;
    Database database;
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
            case 1:
                user.createProfile();
                break;
            case 2:
                user.viewProfile();
                break;
            case 3:
                recipe.addRecipe();
                break;
            case 4:
                recipe.searchRecipe();
                break;
            case 5:
                user.saveRecipe();
                break;
            case 6:
                user.shareRecipe();
                break;
            case 7:
                community.engageDiscussion();
                break;
            case 8:
                community.askQuestion();
                break;
            case 9:
                community.viewDiscussions();
                break;
            case 10:
                cout << "Exiting SocialRecipe. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}