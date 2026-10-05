void addGoal(const char *name, double targetAmount) {
    strcpy(goals[goalCount].name, name);
    goals[goalCount].targetAmount = targetAmount;
    goals[goalCount].currentAmount = 0;
    ++goalCount;
    printf("Goal '%s' added with target amount %.2f.\n", name, targetAmount);
}