void setNutritionalGoals() {
    userGoals.calorieGoal = getIntInput("Enter your daily calorie goal: ");
    userGoals.proteinGoal = getFloatInput("Enter your daily protein goal (g): ");
    userGoals.carbGoal = getFloatInput("Enter your daily carb goal (g): ");
    userGoals.fatGoal = getFloatInput("Enter your daily fat goal (g): ");
    userGoals.fiberGoal = getFloatInput("Enter your daily fiber goal (g): "); 
    userGoals.sugarGoal = getFloatInput("Enter your daily sugar goal (g): "); 
    printf("Your nutritional goals have been set.\n");
}