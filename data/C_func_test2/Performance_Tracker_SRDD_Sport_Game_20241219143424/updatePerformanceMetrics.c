void updatePerformanceMetrics(AthleteList *list) {
    char name[50];
    printf("Enter athlete's name to update metrics: ");
    scanf("%s", name);
    AthleteNode *current = list->head;
    while (current != NULL) {
        if (strcmp(current->athlete.name, name) == 0) {
            printf("Enter new speed (0-100): ");
            scanf("%f", &current->athlete.speed);
            while (current->athlete.speed < 0 || current->athlete.speed > 100) {
                printf("Invalid input. Enter speed (0-100): ");
                scanf("%f", &current->athlete.speed);
            }
            printf("Enter new agility (0-100): ");
            scanf("%f", &current->athlete.agility);
            while (current->athlete.agility < 0 || current->athlete.agility > 100) {
                printf("Invalid input. Enter agility (0-100): ");
                scanf("%f", &current->athlete.agility);
            }
            printf("Enter new accuracy (0-100): ");
            scanf("%f", &current->athlete.accuracy);
            while (current->athlete.accuracy < 0 || current->athlete.accuracy > 100) {
                printf("Invalid input. Enter accuracy (0-100): ");
                scanf("%f", &current->athlete.accuracy);
            }
            printf("Metrics updated successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Athlete not found.\n");
}