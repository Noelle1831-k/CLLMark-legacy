void create_quest() {
    if (quest_count >= MAX_QUESTS) {
        printf("Maximum number of quests reached.\n");
        return;
    }
    Quest new_quest;
    new_quest.id = generate_id();
    printf("Enter quest name: ");
    scanf(" %[^\n]s", new_quest.name);
    printf("Enter quest description: ");
    scanf(" %[^\n]s", new_quest.description);
    printf("Enter quest deadline (YYYY-MM-DD): ");
    scanf(" %[^\n]s", new_quest.deadline);
    new_quest.completed = 0;
    quests[quest_count++] = new_quest;
    printf("Quest created successfully with ID %d.\n", new_quest.id);
}