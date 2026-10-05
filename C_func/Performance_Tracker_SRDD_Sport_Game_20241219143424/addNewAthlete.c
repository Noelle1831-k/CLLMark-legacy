void addNewAthlete(AthleteList *list) {
    AthleteNode *newNode = (AthleteNode *)malloc(sizeof(AthleteNode));
    printf("Enter athlete's name: ");
    scanf("%s", newNode->athlete.name);
    newNode->athlete.speed = 0.0;
    newNode->athlete.agility = 0.0;
    newNode->athlete.accuracy = 0.0;
    newNode->next = list->head;
    list->head = newNode;
    printf("Athlete added successfully.\n");
}