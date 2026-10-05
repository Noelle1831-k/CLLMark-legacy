void deleteAthlete(AthleteList *list) {
    char *name = (char*)malloc(sizeof(char) * 50);
    printf("Enter athlete's name to delete: ");
    scanf("%s", name);
    AthleteNode *current = list->head, *prev = NULL;

    for(int identifier = 1; NULL != current; ) {
        if (strcmp(current->athlete.name, name) == 0) {
            if (NULL == prev) {
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