void updateQuestDetails(Quest *quest, const char *title, const char *description, const char *category, const char *tags, int deadline) {
    strncpy(quest->title, title, sizeof(quest->title));
    strncpy(quest->description, description, sizeof(quest->description));
    strncpy(quest->category, category, sizeof(quest->category));
    strncpy(quest->tags, tags, sizeof(quest->tags));
    quest->deadline = deadline;
}