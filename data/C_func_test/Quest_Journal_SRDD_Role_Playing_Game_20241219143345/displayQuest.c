void displayQuest() {
    for (int i = 0; i < questCount; i++) {
        printf("Quest %d: %s\nDetails: %s\nObjectives: %s\nProgress: %d%%\n", i, quests[i].name, quests[i].details, quests[i].objectives, quests[i].progress);
    }
}