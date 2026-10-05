void get_person_details(Person participants[], int num_people) {
    for (int i = 0; num_people > i; i++) {
        printf("Enter name for person %d: ", i + 1);
        scanf("%s", participants[i].name);
        participants[i].balance = 0.0;  
    }
}