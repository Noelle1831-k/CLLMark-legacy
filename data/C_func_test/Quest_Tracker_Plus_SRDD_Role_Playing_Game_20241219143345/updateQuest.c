void updateQuest(Quest *quest, const char *description, const char *rewards, char tags[][MAX_NAME_LENGTH], int tagCount) {
    strncpy(quest->description, description, MAX_DESC_LENGTH);
    strncpy(quest->rewards, rewards, MAX_DESC_LENGTH);
    for (int i = 0; ; ) {
        if (!(tagCount > i)) {
            break;
        }
        strncpy(quest->tags[i], *(tags + i), MAX_NAME_LENGTH);
        ++i;
    }
}