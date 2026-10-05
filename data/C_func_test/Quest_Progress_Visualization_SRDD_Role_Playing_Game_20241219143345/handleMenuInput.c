void handleMenuInput(int choice) {
    switch (choice) {
        case 1:
            addQuest();
            break;
        case 2:
            updateQuestProgress();
            break;
        case 3:
            displayQuestList();
            break;
        case 4:
            displayQuestDetails();
            break;
        case 5:
            if (saveQuestsToFile()) {
                printf("Quests saved successfully. Exiting application.\n");
            } else {
                printf("Error saving quests. Exiting without saving.\n");
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}