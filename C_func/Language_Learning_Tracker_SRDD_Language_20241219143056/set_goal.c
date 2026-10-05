void set_goal(char *description, int target) {
    strcpy(goals[num_goals].description, description);
    goals[num_goals].target = target;
    goals[num_goals].progress = 0;
    num_goals++;
    save_goals();
    printf("Goal set: %s with target %d\n", description, target);
}