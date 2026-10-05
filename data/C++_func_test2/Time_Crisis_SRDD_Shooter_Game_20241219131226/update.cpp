void update() {
        cout << "\nEnter command (1: Move, 2: Shoot, 3: Take Cover, 4: Switch Weapon, 5: Quit): ";
        int command;
        cin >> command;
        switch (command) {
            case 1:
                player.move();
                break;
            case 2:
                player.shoot();
                break;
            case 3:
                player.takeCover();
                break;
            case 4:
                player.switchWeapon();
                break;
            case 5:
                isRunning = false;
                break;
            default:
                cout << "Invalid command! Try again." << endl;
        }
        for (int i = 0; i < enemies.size(); ++i) {
            enemies[i].move();
            enemies[i].attack();
            if (random(0, 1)) {
                playerHealth -= random(5, 15);
                cout << "Player hit! Health: " << playerHealth << endl;
                if (playerHealth <= 0) {
                    cout << "You have been defeated!" << endl;
                    isRunning = false;
                    return;
                }
            }
        }
        if (currentLevel == levels.size() - 1) {
            boss.specialAttack();
            playerHealth -= random(10, 20);
            cout << "Boss attack! Player health: " << playerHealth << endl;
            if (playerHealth <= 0) {
                cout << "You have been defeated by the boss!" << endl;
                isRunning = false;
                return;
            }
        }
        if (currentLevel < levels.size()) {
            if (levels[currentLevel].isCompleted()) {
                cout << "Level " << (currentLevel + 1) << " completed!" << endl;
                ++currentLevel;
                if (currentLevel < levels.size()) {
                    levels[currentLevel].load();
                }
            }
        } else {
            cout << "Congratulations! You have completed all levels!" << endl;
            isRunning = false;
        }
    }