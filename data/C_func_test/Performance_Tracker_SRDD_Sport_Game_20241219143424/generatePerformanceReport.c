void generatePerformanceReport(AthleteList *list) {
    AthleteNode *current = list->head;
    printf("\nPerformance Report:\n");
    printf("Name\t\tSpeed\tAgility\tAccuracy\tOverall Score\n");
    printf("------------------------------------------------------------\n");
    while (current != NULL) {
        float overallScore = (current->athlete.speed + current->athlete.agility + current->athlete.accuracy) / 3.0;
        printf("%-15s\t%.2f\t%.2f\t%.2f\t\t%.2f\n", current->athlete.name, current->athlete.speed, current->athlete.agility, current->athlete.accuracy, overallScore);
        current = current->next;
    }
}