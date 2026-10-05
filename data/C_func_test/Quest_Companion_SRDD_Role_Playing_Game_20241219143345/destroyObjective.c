void destroyObjective(Objective *objective) {
    free(objective->description);
    free(objective);
}