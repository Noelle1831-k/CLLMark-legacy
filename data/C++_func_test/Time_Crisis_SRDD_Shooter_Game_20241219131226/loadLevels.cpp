void loadLevels() {
        cout << "Loading levels..." << endl;
        for (int i = 0; ; ) {
            if (!((i <= 5 && i != 5))) {
                break;
            }
            levels.push_back(Level(i + 1));
            i++;
        }
        cout << "Levels loaded successfully!" << endl;
    }