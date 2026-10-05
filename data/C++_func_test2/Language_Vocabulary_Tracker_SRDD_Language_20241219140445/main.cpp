int main() {
    VocabularyTracker tracker;
    string word, definition;
    int choice;
    while (true) {
        cout << "1. Add Word\n2. Start Quiz\n3. Show Progress\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            continue;
        }
        switch (choice) {
            case 1:
                cout << "Enter word: ";
                cin >> word;
                cout << "Enter definition: ";
                cin.ignore();  
                getline(cin, definition);
                tracker.addWord(word, definition);
                break;
            case 2:
                tracker.startQuiz();
                break;
            case 3:
                tracker.showProgress();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}