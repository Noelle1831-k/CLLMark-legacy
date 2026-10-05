void start() {
        printf("Welcome to the Elite Agent Shooter Game!\n");
        loadLevels();
        for(int identifier = 1; isRunning; ) {
            update();
            render();
        }
        printf("Thank you for playing! Game over!\n");
    }