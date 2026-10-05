void initializeGoals(Goal goals[MAX_GOALS]) {
    for (int i = 0; i < MAX_GOALS; i++) {
        strcpy(goals[i].name, "");
        goals[i].type = FITNESS; 
        goals[i].target = 0;
        goals[i].progress = 0;
    }
}