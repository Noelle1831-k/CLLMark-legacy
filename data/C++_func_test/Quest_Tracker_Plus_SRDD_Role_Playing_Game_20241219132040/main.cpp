int main() {
    UserInterface ui;
    QuestManager questManager;
    QuestGuide questGuide;
    int choice;
    do {
        ui.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string name, description, category, reward;
                int tagCount;
                vector<string> tags;
                cout << "Enter quest name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter quest description: ";
                getline(cin, description);
                cout << "Enter quest category: ";
                getline(cin, category);
                cout << "Enter quest reward: ";
                getline(cin, reward);
                cout << "Enter number of tags: ";
                cin >> tagCount;
                cin.ignore();
                for (int i = 0; i < tagCount; i++) {
                    string tag;
                    cout << "Enter tag " << (i + 1) << ": ";
                    getline(cin, tag);
                    tags.push_back(tag);
                }
                Quest newQuest(name, description, category, tags, reward);
                questManager.addQuest(newQuest);
                cout << "Quest added successfully!\n";
                break;
            }
            case 2: {
                string questName;
                cout << "Enter the name of the quest to delete: ";
                cin.ignore();
                getline(cin, questName);
                questManager.deleteQuest(questName);
                break;
            }
            case 3: {
                string questName, newStatus;
                cout << "Enter the name of the quest to update: ";
                cin.ignore();
                getline(cin, questName);
                cout << "Enter new status (Not Started/In Progress/Completed): ";
                getline(cin, newStatus);
                questManager.updateQuest(questName, newStatus);
                break;
            }
            case 4:
                questManager.listQuests();
                break;
            case 5: {
                string questName, hint;
                cout << "Enter the name of the quest to add a hint for: ";
                cin.ignore();
                getline(cin, questName);
                cout << "Enter the hint: ";
                getline(cin, hint);
                questGuide.addHint(questName, hint);
                cout << "Hint added successfully!\n";
                break;
            }
            case 6: {
                string questName;
                cout << "Enter the name of the quest to get a hint for: ";
                cin.ignore();
                getline(cin, questName);
                cout << "Hint: " << questGuide.getHint(questName) << endl;
                break;
            }
            case 7:
                questGuide.listHints();
                break;
            case 8:
                cout << "Exiting Quest Tracker Plus. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);
    return 0;
}