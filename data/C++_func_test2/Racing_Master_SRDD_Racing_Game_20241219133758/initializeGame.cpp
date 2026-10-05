void initializeGame() {
        cout << "Initializing Racing Master..." << endl;
        srand(time(0)); 
        createTeams();
        createRaces();
    }