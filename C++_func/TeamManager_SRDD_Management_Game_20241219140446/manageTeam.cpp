void TeamManager::manageTeam() {
    int choice;
    while (true) {
        cout << "\n1. Display Team\n2. Train Players\n3. Set Strategy\n4. Recruit Player\n5. Simulate Match\n6. Exit\nChoose an action: ";
        cin >> choice;
        switch (choice) {
        case 1:
            team.displayTeam();
            break;
        case 2:
            for (int i = 0; i < team.getPlayers().size(); i++) {
                team.getPlayers()[i].train();
            }
            break;
        case 3:
            {
                string strategy;
                cout << "Enter new strategy (e.g., Aggressive, Defensive): ";
                cin >> strategy;
                team.setStrategy(strategy);
            }
            break;
        case 4:
            displayFreeAgents();
            int playerChoice;
            cout << "Select a free agent to recruit (0 to cancel): ";
            cin >> playerChoice;
            if (playerChoice > 0 && playerChoice <= freeAgents.size()) {
                team.addPlayer(freeAgents[playerChoice - 1]);
                freeAgents.erase(freeAgents.begin() + (playerChoice - 1));
            }
            break;
        case 5:
            runMatch();
            break;
        case 6:
            cout << "Exiting game. Goodbye!" << endl;
            return;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}