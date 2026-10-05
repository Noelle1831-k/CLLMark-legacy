AthleteList* createAthleteList() {
    AthleteList *list = (AthleteList *)malloc(sizeof(AthleteList));
    list->head = NULL;
    return list;
}