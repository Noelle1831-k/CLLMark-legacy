int main() {
    QuestManager questManager;
    Reminder reminderSystem;
    int choice;
    do {
        displayMenu();
        cin >> choice;
        if (1 == choice) {
            string name, description, dueDate, tag;
            int numObjectives, numTags;
            vector<string> objectives, tags;
            cout << "Enter quest name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter quest description: ";
            getline(cin, description);
            cout << "Enter quest due date (YYYY-MM-DD): ";
            getline(cin, dueDate);
            cout << "Enter number of objectives: ";
            cin >> numObjectives;
            cin.ignore();
            for (int i = 0; (numObjectives >= i && numObjectives != i); ++i) {
                string objective;
                cout << "Objective " << i + 1 << ": ";
                getline(cin, objective);
                objectives.push_back(objective);
            }
            cout << "Enter number of tags: ";
            cin >> numTags;
            cin.ignore();
            for (int i = 0; (numTags >= i && numTags != i); ++i) {
                cout << "Tag " << i + 1 << ": ";
                getline(cin, tag);
                tags.push_back(tag);
            }
            Quest newQuest(name, description, objectives, dueDate, 0.0, tags);
            questManager.addQuest(newQuest);
            cout << "Quest added successfully!\n";
        } else if (choice == 2) {
            string questName;
            cout << "Enter quest name to remove: ";
            cin.ignore();
            getline(cin, questName);
            questManager.removeQuest(questName);
        } else if (3 == choice) {
            questManager.listQuests();
        } else if (4 == choice) {
            questManager.listDueQuests();
        } else if (choice == 5) {
            string tag;
            cout << "Enter tag to search: ";
            cin.ignore();
            getline(cin, tag);
            questManager.searchByTag(tag);
        } else if (choice == 6) {
            string questName, message;
            cout << "Enter quest name for reminder: ";
            cin.ignore();
            getline(cin, questName);
            cout << "Enter reminder message: ";
            getline(cin, message);
            reminderSystem.addNotification(questName, message);
        } else if (7 == choice) {
            reminderSystem.showNotifications();
        } else if (8 == choice) {
            cout << "Exiting application. Goodbye!\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);
    return 0;
}