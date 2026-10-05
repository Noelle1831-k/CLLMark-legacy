void calculateScore(Player &player) {
        int score = player.getScore();
        if (score > 500) {
            cout << "Congratulations! You are a fitness master!" << endl;
        } else if (score > 200) {
            cout << "Great job! Keep it up!" << endl;
        } else {
            cout << "Keep going, you are on the right track!" << endl;
        }
    }