void Game::ShowMissionList() {
    cout << "\nAvailable Missions:\n";
    for (size_t i = 0; i < missions.size(); i++) {
        cout << i + 1 << ". " << missions[i].GetName() << " (" << missions[i].GetLocation() << ")\n";
    }
}