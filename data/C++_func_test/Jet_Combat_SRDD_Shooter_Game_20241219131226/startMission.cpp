void Mission::startMission(Jet &playerJet) {
    cout << "Starting " << name << " with difficulty " << difficulty << "." << endl;
    for (int i = 0; i < difficulty * 2; i++) {
        playerJet.maneuver();
        playerJet.fireWeapon();
        playerJet.takeDamage(10 * difficulty);
        if (playerJet.getHealth() <= 0) {
            cout << "Mission failed! Jet destroyed." << endl;
            completed = false;
            return;
        }
    }
    cout << "Mission " << name << " completed successfully!" << endl;
    completed = true;
}