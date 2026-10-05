void play() override {
        cout << "Solving a mindfulness puzzle..." << endl;
        int puzzleSize = 4;
        vector<vector<int>> puzzle(puzzleSize, vector<int>(puzzleSize));
        srand(time(0));
        for (int i = 0; i < puzzleSize; i++) {
            for (int j = 0; j < puzzleSize; j++) {
                puzzle[i][j] = rand() % 10;
            }
        }
        for (int i = 0; i < puzzleSize; i++) {
            for (int j = 0; j < puzzleSize; j++) {
                cout << puzzle[i][j] << " ";
            }
            cout << endl;
        }
        this_thread::sleep_for(chrono::seconds(3));
        cout << "Puzzle solved!" << endl;
    }