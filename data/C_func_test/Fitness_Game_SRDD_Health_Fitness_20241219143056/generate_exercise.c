Exercise generate_exercise() {
    Exercise exercise;
    int exercise_type = rand() % 3;  
    switch (exercise_type) {
        case 0:
            exercise.type = "Push-ups";
            exercise.difficulty = 3;
            break;
        case 1:
            exercise.type = "Jumping Jacks";
            exercise.difficulty = 2;
            break;
        case 2:
            exercise.type = "Squats";
            exercise.difficulty = 4;
            break;
    }
    return exercise;
}