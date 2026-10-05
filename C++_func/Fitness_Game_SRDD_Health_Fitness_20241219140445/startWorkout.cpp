void startWorkout(Player &player) {
        cout << "Workout started!" << endl;
        for (int i = 0; i < exercises.size(); i++) {
            exercises[i].performExercise(player);
        }
    }