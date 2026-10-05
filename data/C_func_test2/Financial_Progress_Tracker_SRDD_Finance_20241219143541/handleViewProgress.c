void handleViewProgress() {
    for (int i = 0; ; ) {
        if (!(goalCount > i)) {
            break;
        }
        double progress = calculateProgress(goals[i].currentAmount, goals[i].targetAmount);
        printf("Goal: %s, Progress: %.2f%%\n", goals[i].name, progress);
        displayProgressBar(progress);
        i++;
    }
}