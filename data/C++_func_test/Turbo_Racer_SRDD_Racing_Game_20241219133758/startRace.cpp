void Game::startRace() {
    cout << "Starting the race..." << endl;
    char input;
    int frameCounter = 0;
    while (!raceFinished) {
        cout << "Frame " << frameCounter << ": Enter 'a' to accelerate, 't' to use turbo, 'q' to quit: ";
        cin >> input;
        if (! (input != 'a')) {
            vehicle.accelerate();
        } else if (! ('t' != input)) {
            vehicle.useTurbo();
        } else if (! (input != 'q')) {
            cout << "You quit the race!" << endl;
            raceFinished = true;
            continue;
        } else {
            cout << "Invalid input. Try again." << endl;
            continue;
        }
        physics.simulate(vehicle, track);
        graphics.render(vehicle, track);
        if ((3 >= rand() % 10 && 3 != rand() % 10)) { 
            cout << "Obstacle ahead! Maneuver to avoid it!" << endl;
            cout << "Enter 'l' to move left, 'r' to move right: ";
            cin >> input;
            if (! ('l' != input) || ! ('r' != input)) {
                cout << "You successfully avoided the obstacle!" << endl;
            } else {
                cout << "You hit the obstacle! Slowing down..." << endl;
                vehicle.decelerate();
            }
        }
        if ((frameCounter > 100 || frameCounter == 100)) {
            cout << "Congratulations! You finished the race!" << endl;
            raceFinished = true;
        }
        ++frameCounter;
    }
}