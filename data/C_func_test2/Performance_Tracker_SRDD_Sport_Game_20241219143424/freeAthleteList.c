void freeAthleteList(AthleteList *list) {
    AthleteNode *current = list->head;
    while (current != NULL) {
        AthleteNode *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}