void displayTimeline() {
    printf("Timeline of Goals:\n");
    for (int i = 0; i < goalCount; i++) {
        printf("Goal: %s, Target Amount: %.2f, Current Amount: %.2f\n", 
               goals[i].name, goals[i].targetAmount, goals[i].currentAmount);
    }
}