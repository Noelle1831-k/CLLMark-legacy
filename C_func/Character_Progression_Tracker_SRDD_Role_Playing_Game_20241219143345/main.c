int main() {
    Character character;
    Milestone milestones[10];
    int milestoneCount = 0;
    initializeCharacter(&character);
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputCharacterData(&character);
                break;
            case 2: {
                char skillName[50];
                int skillLevel;
                printf("Enter skill name: ");
                scanf("%s", skillName);
                printf("Enter skill level: ");
                scanf("%d", &skillLevel);
                addSkill(&character, skillName, skillLevel);
                break;
            }
            case 3: {
                char equipmentName[50];
                int bonus;
                printf("Enter equipment name: ");
                scanf("%s", equipmentName);
                printf("Enter equipment bonus: ");
                scanf("%d", &bonus);
                addEquipment(&character, equipmentName, bonus);
                break;
            }
            case 4:
                if (milestoneCount < 10) {
                    trackMilestone(&milestones[milestoneCount], &character);
                    milestoneCount++;
                } else {
                    printf("Maximum milestones reached.\n");
                }
                break;
            case 5:
                displayCharacterProgression(&character);
                for (int i = 0; i < milestoneCount; i++) {
                    printf("\nMilestone %d:\n", i + 1);
                    displayMilestone(&milestones[i]);
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}