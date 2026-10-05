Quest* createQuest(const char *name, const char *description) {
    Quest *quest = (Quest*)malloc(sizeof(Quest));
    quest->name = strdup(name);
    quest->description = strdup(description);
    quest->objectives = NULL;
    quest->objectiveCount = 0;
    return quest;
}