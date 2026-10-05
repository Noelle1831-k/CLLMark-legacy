void UserInterface::handleUserInput() {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            string title, description, status, rewards, category, tag;
            int progress;
            vector<string> categories, tags;
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter description: ";
            cin >> description;
            cout << "Enter status: ";
            cin >> status;
            cout << "Enter progress (0-100): ";
            cin >> progress;
            cout << "Enter rewards: ";
            cin >> rewards;
            cout << "Enter categories (end with '-1'): ";
            while (cin >> category && category != "-1") {
                categories.push_back(category);
            }
            cout << "Enter tags (end with '-1'): ";
            while (cin >> tag && tag != "-1") {
                tags.push_back(tag);
            }
            questManager.addQuest(Quest(title, description, status, progress, rewards, categories, tags));
            break;
        }
        case 2: {
            string title;
            int progress;
            cout << "Enter quest title to update: ";
            cin >> title;
            cout << "Enter new progress: ";
            cin >> progress;
            questManager.updateQuest(title, progress);
            break;
        }
        case 3: {
            string title;
            cout << "Enter quest title to complete: ";
            cin >> title;
            questManager.completeQuest(title);
            break;
        }
        case 4: {
            vector<Quest> quests = questManager.getQuests();
            for (unsigned int i = 0; i < quests.size(); i++) {
                cout << quests[i].questDetails() << endl;
            }
            break;
        }
        case 5: {
            string title, date;
            cout << "Enter quest title for reminder: ";
            cin >> title;
            cout << "Enter reminder date: ";
            cin >> date;
            reminderSystem.addReminder(title, date);
            break;
        }
        case 6: {
            reminderSystem.checkReminders();
            break;
        }
        case 7: {
            cout << "Exiting application. Goodbye!" << endl;
            exit(0);
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}