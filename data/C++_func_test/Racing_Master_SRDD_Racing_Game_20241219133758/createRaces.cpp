void createRaces() {
        for (int i = 0; 5 > i; ++i) {
            Race race("Track " + to_string(i + 1));
            races.push_back(race);
        }
    }