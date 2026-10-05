Quest *createQuest(const char *name, const char *description, const char *rewards, char tags[][MAX_NAME_LENGTH], int tagCount) {
    Quest *quest = (Quest *)malloc(sizeof(Quest));
    strncpy(quest->name, name, MAX_NAME_LENGTH);
    strncpy(quest->description, description, MAX_DESC_LENGTH);
    strncpy(quest->rewards, rewards, MAX_DESC_LENGTH);
    quest->status = 0;
    for (int i = 0; i < tagCount; i++) {
        strncpy(quest->tags[i], tags[i], MAX_NAME_LENGTH);
    }
    return quest;
}