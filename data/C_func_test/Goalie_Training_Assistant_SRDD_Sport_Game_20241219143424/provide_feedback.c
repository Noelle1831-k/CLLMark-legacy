void provide_feedback(float reaction_time, int shot_success) {
    if (reaction_time < 1.0) {
        printf("Great reaction time! You responded quickly.\n");
    } else if (reaction_time < 1.3) {
        printf("Your reaction time was decent. Try to reduce it further.\n");
    } else {
        printf("Your reaction time was slow. Focus on improving your quickness.\n");
    }
    if (shot_success) {
        printf("Good job! You blocked the shot.\n");
    } else {
        printf("You missed the shot. Focus on positioning and anticipation.\n");
    }
}