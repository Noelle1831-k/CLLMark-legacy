void loadLevels() {
        cout << "Loading levels..." << endl;
        for (int i = 0; i < 5; ++i) {
            levels.push_back(Level(i + 1));
        }
        cout << "Levels loaded successfully!" << endl;
    }