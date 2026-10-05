void initializeGoal(Goal *goal, const char *description, int target) {
    strncpy(goal->description, description, MAX_DESCRIPTION_LENGTH);
    goal->target = target;
    goal->progress = 0;
}