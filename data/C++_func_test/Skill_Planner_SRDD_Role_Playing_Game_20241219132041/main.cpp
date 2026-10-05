int main(void) {
    SkillPlanner planner;
    int choice;
    while (true) {
        DisplayMenu();
        cin >> choice;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        switch (choice) {
            case 1:
                planner.CreateCharacter();
                break;
            case 2:
                planner.AddSkillToCharacter();
                break;
            case 3:
                planner.RemoveSkillFromCharacter();
                break;
            case 4:
                planner.DisplayPlanner();
                break;
            case 5:
                cout << "Exiting Skill Planner. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}