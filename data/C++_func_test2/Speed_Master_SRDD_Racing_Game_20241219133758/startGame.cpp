void Game::startGame() {
    cout << "Select your vehicle:" << endl;
    cout << "1. Speedster\n2. Drift King\n3. Turbo Tank\n";
    int choice;
    cin >> choice;
    if (choice == 1) playerVehicle = new Vehicle("Speedster", 220, 80, 100);
    else if (choice == 2) playerVehicle = new Vehicle("Drift King", 200, 95, 80);
    else playerVehicle = new Vehicle("Turbo Tank", 180, 70, 150);
    cout << "Choose a track difficulty (1- Easy, 2- Medium, 3- Hard): ";
    int difficulty;
    cin >> difficulty;
    selectedTrack = new Track(difficulty);
    selectedTrack->generateTrack();
    startRace();
}