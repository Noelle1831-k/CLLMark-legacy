void Game::PlayMission(Mission& mission) {
    cout << "\nStarting " << mission.GetName() << " at " << mission.GetLocation() << "...\n";
    if (mission.CompleteMission(player)) {
        cout << "Mission completed successfully!\n";
    } else {
        cout << "Mission failed. Better luck next time!\n";
    }
}