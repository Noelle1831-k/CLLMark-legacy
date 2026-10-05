void compareGoals(int index) {
    if (family[index].currentNutrition >= family[index].nutritionGoal) {
        printf("Congratulations! You've reached your nutrition goal for today.\n");
    } else {
        printf("You need %d more grams of nutrition to reach your goal today.\n",
               family[index].nutritionGoal - family[index].currentNutrition);
    }
    if (family[index].currentActivity >= family[index].activityGoal) {
        printf("Great job! You've met your physical activity goal for today.\n");
    } else {
        printf("You need %d more minutes of activity to reach your goal today.\n",
               family[index].activityGoal - family[index].currentActivity);
    }
    if (family[index].currentSleep >= family[index].sleepGoal) {
        printf("Well done! You've reached your sleep goal for today.\n");
    } else {
        printf("You need %d more hours of sleep to reach your goal today.\n",
               family[index].sleepGoal - family[index].currentSleep);
    }
    if (family[index].currentScreenTime <= family[index].screenTimeGoal) {
        printf("Good job! You've stayed within your screen time goal for today.\n");
    } else {
        printf("You exceeded your screen time goal by %d hours.\n",
               family[index].currentScreenTime - family[index].screenTimeGoal);
    }
}