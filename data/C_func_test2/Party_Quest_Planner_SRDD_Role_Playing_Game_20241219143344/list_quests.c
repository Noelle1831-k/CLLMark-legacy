void list_quests() {
    if (quest_count == 0) {
        printf("No quests available.\n");
        return;
    }
    printf("\n---- Quest List ----\n");
    for (int i = 0; i < quest_count; i++) {
        printf("ID: %d | Name: %s | Deadline: %s | Completed: %s\n",
               quests[i].id, quests[i].name, quests[i].deadline,
               quests[i].completed ? "Yes" : "No");
    }
}