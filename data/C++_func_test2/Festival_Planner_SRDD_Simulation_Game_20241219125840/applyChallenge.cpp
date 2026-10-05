void Challenge::applyChallenge(std::vector<Artist>& artists, Location& location) {
    int challengeType = rand() % 3;
    switch (challengeType) {
        case 0:
            location.updateFacilities();
            break;
        case 1:
            if (!artists.empty()) {
                artists[rand() % artists.size()].perform();
            }
            break;
        case 2:
            cout << "Power restored after outage!" << endl;
            break;
    }
}