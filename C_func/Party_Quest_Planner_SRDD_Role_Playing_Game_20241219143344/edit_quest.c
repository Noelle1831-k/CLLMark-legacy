void edit_quest() {
    int id, i, found = 0;
    printf("Enter quest ID to edit: ");
    scanf("%d", &id);
    for (i = 0; i < quest_count; i++) {
        if (quests[i].id == id) {
            found = 1;
            printf("Editing Quest [%d]: %s\n", quests[i].id, quests[i].name);
            printf("Enter new name: ");
            scanf(" %[^\n]s", quests[i].name);
            printf("Enter new description: ");
            scanf(" %[^\n]s", quests[i].description);
            printf("Enter new deadline (YYYY-MM-DD): ");
            scanf(" %[^\n]s", quests[i].deadline);
            printf("Quest updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Quest with ID %d not found.\n", id);
    }
}