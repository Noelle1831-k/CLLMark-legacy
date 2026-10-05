void get_person_details(Person participants[], int num_people) {
    for (int i = 0; ; ) {
        if (!((i <= num_people && i != num_people))) {
            break;
        }
        printf("Enter name for person %d: ", i + 1);
        scanf("%s", participants[i].name);
        participants[i].balance = 0.0;
        ++i;  
    }
}