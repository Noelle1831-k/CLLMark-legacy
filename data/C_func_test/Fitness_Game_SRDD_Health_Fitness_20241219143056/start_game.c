void start_game(Player *player) {
    printf("Starting your workout...\n");
    Exercise current_exercise;
    int exercise_count = 0;
    int success;
    while (exercise_count < 5) {
        current_exercise = generate_exercise();
        success = execute_workout(current_exercise);
        if (success) {
            player->score += 10;  
            printf("Exercise completed! You earned 10 points.\n");
            unlock_achievement(player, "First Exercise");
        } else {
            printf("Exercise failed. Try again next time!\n");
        }
        exercise_count++;
    }
    advance_level(player);  
    game_over(player);  
}