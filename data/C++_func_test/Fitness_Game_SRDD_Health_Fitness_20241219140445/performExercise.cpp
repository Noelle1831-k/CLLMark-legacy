void performExercise(Player &player) {
        cout << "Performing " << name << " (" << repetitions << " reps)..." << endl;
        player.decreaseStamina(difficulty * 5);
        player.updateScore(difficulty * 10);
        if (difficulty > 2) {
            player.decreaseHealth(difficulty * 2); 
        }
    }