void manageQuests() {
    int choice;
    do {
        printf("\nQuest Management:\n1. Create Quest\n2. Update Quest\n3. Display Quests\n4. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createQuest();
                break;
            case 2:
                updateQuest();
                break;
            case 3:
                displayQuest();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}