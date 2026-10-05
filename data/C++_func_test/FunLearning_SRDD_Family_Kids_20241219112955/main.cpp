int main() {
    int choice;
    bool running = true;
    while (running) {
        clearScreen();
        displayMessage("Welcome to FunLearning!", 1); 
        cout << "\n1. Math Game\n2. Science Game\n3. Language Arts Game\n4. Social Studies Game\n5. Exit\n";
        cout << "Please select an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                startMathGame();
                break;
            case 2:
                startScienceGame();
                break;
            case 3:
                startLanguageArtsGame();
                break;
            case 4:
                startSocialStudiesGame();
                break;
            case 5:
                running = false;
                displayMessage("Thank you for using FunLearning!", 2);
                break;
            default:
                displayMessage("Invalid option! Please try again.", 0);
                break;
        }
    }
    return 0;
}