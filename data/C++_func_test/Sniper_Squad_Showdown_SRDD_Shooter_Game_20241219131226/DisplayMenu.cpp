void Game::DisplayMenu() {
    int choice;
    while (true) {
        cout << "\nMain Menu:\n";
        cout << "1. View Missions\n2. Play Mission\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            ShowMissionList();
        } else if (choice == 2) {
            int missionIndex;
            ShowMissionList();
            cout << "Select a mission to play: ";
            cin >> missionIndex;
            if (missionIndex >= 1 && missionIndex <= missions.size()) {
                PlayMission(missions[missionIndex - 1]);
            } else {
                cout << "Invalid mission choice.\n";
            }
        } else if (choice == 3) {
            cout << "Exiting game. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}