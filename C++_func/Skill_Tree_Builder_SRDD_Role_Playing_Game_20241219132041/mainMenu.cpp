void UserInterface::mainMenu() {
    int choice;
    do {
        cout << "\nSkill Tree Builder\n";
        cout << "1. Create Root Skill\n";
        cout << "2. Add Skill to Tree\n";
        cout << "3. View Skill Tree\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                createSkill();
                break;
            case 2:
                buildSkillTree();
                break;
            case 3:
                viewSkillTree();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);
}