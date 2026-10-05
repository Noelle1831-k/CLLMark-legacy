Objective* createObjective(const char *description) {
    Objective *objective = (Objective*)malloc(sizeof(Objective));
    objective->description = strdup(description);
    objective->completed = 0;
    return objective;
}