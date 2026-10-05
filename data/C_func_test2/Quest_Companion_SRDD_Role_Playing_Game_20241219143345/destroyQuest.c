void destroyQuest(Quest *quest) {
    for (int i = 0; i < quest->objectiveCount; i++) {
        destroyObjective(quest->objectives[i]);
    }
    free(quest->objectives);
    free(quest->name);
    free(quest->description);
    free(quest);
}