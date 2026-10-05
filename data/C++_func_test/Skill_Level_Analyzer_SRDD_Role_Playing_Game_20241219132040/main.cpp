int main() {
    SkillAnalyzer analyzer;
    Player player;
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            Skill skill;
            skill.setParameters();
            analyzer.addSkill(skill);
        } else if (choice == 2) {
            player.setPlayerAttributes();
        } else if (choice == 3) {
            analyzer.analyzeSkills();
        } else if (choice == 4) {
            analyzer.suggestSkills(player);
        } else if (choice == 5) {
            cout << "Exiting Skill Level Analyzer. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}