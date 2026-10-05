void createRaces() {
        for (int i = 0; i < 5; i++) {
            Race race("Track " + to_string(i + 1));
            races.push_back(race);
        }
    }