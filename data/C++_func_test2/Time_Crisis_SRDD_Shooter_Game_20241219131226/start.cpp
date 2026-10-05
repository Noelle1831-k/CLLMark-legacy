void start() {
        cout << "Welcome to the Elite Agent Shooter Game!" << endl;
        loadLevels();
        while (isRunning) {
            update();
            render();
        }
        cout << "Thank you for playing! Game over!" << endl;
    }