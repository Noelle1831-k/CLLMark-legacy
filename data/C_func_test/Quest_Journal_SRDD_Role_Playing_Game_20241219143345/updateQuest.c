void updateQuest() {
    int index;
    printf("Enter quest index to update: ");
    scanf("%d", &index);
    if (index >= 0 && index < questCount) {
        printf("Enter new progress: ");
        scanf("%d", &quests[index].progress);
    } else {
        printf("Invalid quest index.\n");
    }
}