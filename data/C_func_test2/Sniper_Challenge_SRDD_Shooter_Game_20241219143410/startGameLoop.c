void startGameLoop() {
    displayMessage("Game loop started. Good luck!\n");
    while (!gameOver) {
        if (_kbhit()) { 
            char input = _getch();
            switch (input) {
                case 's': 
                    if (ammoAvailable()) {
                        shootTarget();
                    } else {
                        displayMessage("Out of ammo! Reload to continue.");
                    }
                    break;
                case 'r': 
                    reloadAmmo();
                    break;
                case 'q': 
                    displayMessage("Quitting the game...");
                    gameOver = 1;
                    break;
                default:
                    displayMessage("Invalid input. Press 's' to shoot, 'r' to reload, 'q' to quit.");
                    break;
            }
        }
        updateTargets();
        if (checkGameOverCondition()) {
            displayMessage("Game Over! Thanks for playing.");
            gameOver = 1;
        }
        for (volatile int i = 0; i < 5000000; i++);
    }
}