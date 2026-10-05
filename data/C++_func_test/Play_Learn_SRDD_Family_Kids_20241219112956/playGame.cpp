void playGame(int choice) {
        if (choice >= 1 && choice <= 4) {
            games[choice - 1]->play();
            tracker.updateProgress(player, games[choice - 1]);
            recommender.suggestGames(player);
        } else if (choice == 5) {
            tracker.displayProgress(player);
        }
    }