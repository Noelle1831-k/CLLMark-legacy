void addObjective(Quest *quest, Objective *objective) {
    quest->objectives = (Objective**)realloc(quest->objectives, sizeof(Objective*) * (quest->objectiveCount + 1));
    quest->objectives[quest->objectiveCount++] = objective;
}