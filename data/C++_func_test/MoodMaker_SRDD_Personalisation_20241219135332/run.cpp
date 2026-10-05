void run() {
        songDatabase.loadSongs();
        while (true) {
            displayMenu();
            handleUserInput();
        }
    }