void deleteAthlete(AthleteList *list) {
    char name[50];
    printf("Enter athlete's name to delete: ");
    scanf("%s", name);
    AthleteNode *current = list->head;
    AthleteNode *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->athlete.name, name) == 0) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Athlete deleted successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Athlete not found.\n");
}