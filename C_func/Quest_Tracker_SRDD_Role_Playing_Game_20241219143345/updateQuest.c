void updateQuest(QuestManager *manager, int id) {
    for (int i = 0; i < manager->count; i++) {
        if (manager->quests[i].id == id) {
            char title[100], description[255], category[50], tags[100];
            int deadline;
            printf("Enter New Title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = '\0';
            printf("Enter New Description: ");
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = '\0';
            printf("Enter New Category: ");
            fgets(category, sizeof(category), stdin);
            category[strcspn(category, "\n")] = '\0';
            printf("Enter New Tags (comma-separated): ");
            fgets(tags, sizeof(tags), stdin);
            tags[strcspn(tags, "\n")] = '\0';
            printf("Enter New Deadline (in days): ");
            scanf("%d", &deadline);
            updateQuestDetails(&manager->quests[i], title, description, category, tags, deadline);
            printf("Quest updated successfully!\n");
            return;
        }
    }
    printf("Quest not found!\n");
}