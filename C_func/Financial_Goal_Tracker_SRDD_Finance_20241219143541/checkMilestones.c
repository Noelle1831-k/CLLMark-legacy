void checkMilestones(Goal goals[], int goalCount) {
    for (int i = 0; i < goalCount; i++) {
        for (int j = 0; j < goals[i].milestoneCount; j++) {
            if (goals[i].currentAmount >= goals[i].milestones[j]) {
                printf("Milestone %.2f reached for goal '%s'!\n", goals[i].milestones[j], goals[i].name);
            }
        }
    }
}