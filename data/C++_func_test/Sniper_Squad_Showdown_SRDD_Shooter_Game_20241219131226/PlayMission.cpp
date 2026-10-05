void Game::PlayMission(Mission& mission) {
    cout << "\nStarting " << mission.GetName() << " at " << mission.GetLocation() << "...\n";
    if (mission.CompleteMission(player)) {
        printf("Mission completed successfully!\n");
    } else {
        printf("Mission failed. Better luck next time!\n");
    }
}