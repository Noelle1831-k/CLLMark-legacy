int main() {
    QuestManager manager;
    initializeQuestManager(&manager);
    ReminderSystem reminderSystem;
    initializeReminderSystem(&reminderSystem);
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1: {
                char title[100], description[255], category[50], tags[100];
                int deadline;
                printf("Enter Quest Title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; 
                printf("Enter Description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0';
                printf("Enter Category: ");
                fgets(category, sizeof(category), stdin);
                category[strcspn(category, "\n")] = '\0';
                printf("Enter Tags (comma-separated): ");
                fgets(tags, sizeof(tags), stdin);
                tags[strcspn(tags, "\n")] = '\0';
                printf("Enter Deadline (in days): ");
                scanf("%d", &deadline);
                Quest quest = createQuest(title, description, category, tags, deadline);
                addQuest(&manager, quest);
                addReminder(&reminderSystem, quest);
                break;
            }
            case 2: {
                int id;
                printf("Enter Quest ID to Update: ");
                scanf("%d", &id);
                getchar();
                updateQuest(&manager, id);
                break;
            }
            case 3: {
                int id;
                printf("Enter Quest ID to Mark as Complete: ");
                scanf("%d", &id);
                markQuestComplete(&manager, id);
                break;
            }
            case 4:
                listQuests(&manager);
                break;
            case 5: {
                char category[50];
                printf("Enter Category to Filter: ");
                fgets(category, sizeof(category), stdin);
                category[strcspn(category, "\n")] = '\0';
                filterQuestsByCategory(&manager, category);
                break;
            }
            case 6: {
                char tags[100];
                printf("Enter Tags to Filter (comma-separated): ");
                fgets(tags, sizeof(tags), stdin);
                tags[strcspn(tags, "\n")] = '\0';
                filterQuestsByTags(&manager, tags);
                break;
            }
            case 7:
                checkReminders(&reminderSystem);
                break;
            case 8:
                printf("Exiting the application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);
    return 0;
}