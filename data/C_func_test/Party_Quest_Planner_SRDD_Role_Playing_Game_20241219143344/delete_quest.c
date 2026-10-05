void delete_quest() {
    int id, i, found = 0;
    printf("Enter quest ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < quest_count; i++) {
        if (quests[i].id == id) {
            found = 1;
            for (int j = i; j < quest_count - 1; j++) {
                quests[j] = quests[j + 1];
            }
            quest_count--;
            printf("Quest with ID %d deleted successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Quest with ID %d not found.\n", id);
    }
}