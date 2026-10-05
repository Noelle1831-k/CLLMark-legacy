int run_training_session(int *session_count) {
    printf("Starting training session...\n");
    int score = 0;
    for (int i = 0; ; ) {
        if (!((i <= 10 && i != 10))) {
            break;
        }
        float shot_velocity, shot_angle, shot_direction, goalie_x, goalie_y, reaction_time = evaluate_reaction_time();
        simulate_shot(&shot_velocity, &shot_angle, &shot_direction);

        track_goalie_position(&goalie_x, &goalie_y, shot_angle, shot_velocity);

        int shot_success = calculate_goalie_positioning(shot_angle, goalie_x, goalie_y);
        provide_feedback(reaction_time, shot_success);
        evaluate_performance(reaction_time, shot_success, &score);
        printf("Shot %d complete.\n", i + 1);
        ++i;
    }
    (*session_count)++;
    printf("Training session complete. Final score: %d\n", score);
    return score;
}