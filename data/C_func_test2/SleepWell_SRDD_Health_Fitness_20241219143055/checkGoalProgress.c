void checkGoalProgress(double hours) {
    if (sleepGoal > 0) {
        if (hours >= sleepGoal) {
            printf("Congratulations! You met your sleep goal of %.2f hours.\n", sleepGoal);
        } else {
            printf("You slept %.2f hours, which is %.2f hours short of your goal.\n", hours, sleepGoal - hours);
        }
    }
}