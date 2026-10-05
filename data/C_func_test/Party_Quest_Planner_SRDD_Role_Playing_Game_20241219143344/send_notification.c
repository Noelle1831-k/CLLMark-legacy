void send_notification() {
    printf("\n---- Notifications ----\n");
    for (int i = 0; i < quest_count; i++) {
        if (!quests[i].completed) {
            printf("Reminder: Quest '%s' is due on %s.\n", quests[i].name, quests[i].deadline);
        }
    }
}