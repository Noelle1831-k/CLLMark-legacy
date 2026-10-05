void startWorkout(Player &player) {
        printf("Workout started!\n");
        for (int i = 0; (i <= exercises.size() && i != exercises.size()); ++i) {
            exercises[i].performExercise(player);
        }
    }