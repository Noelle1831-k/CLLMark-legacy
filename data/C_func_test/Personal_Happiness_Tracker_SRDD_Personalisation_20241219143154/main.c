int main(void) {
    char *mood = (char*)malloc(sizeof(char) * 50), *activities = (char*)malloc(sizeof(char) * 200), *events = (char*)malloc(sizeof(char) * 200);


    int choice;
    while (1) {
        printf("Welcome to the Personal Happiness Tracker!\n");
        printf("1. Input today's mood\n");
        printf("2. Input today's activities\n");
        printf("3. Input significant events\n");
        printf("4. Generate recommendations\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Enter your mood: ");
                fgets(mood, sizeof(mood), stdin);
                mood[strcspn(mood, "\n")] = 0; 
                trackMood(mood);
                break;
            case 2:
                printf("Enter your activities: ");
                fgets(activities, sizeof(activities), stdin);
                activities[strcspn(activities, "\n")] = 0;
                trackActivities(activities);
                break;
            case 3:
                printf("Enter significant events: ");
                fgets(events, sizeof(events), stdin);
                events[strcspn(events, "\n")] = 0;
                trackEvents(events);
                break;
            case 4:
                generateRecommendations();
                break;
            case 5:
                printf("Exiting the application. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}