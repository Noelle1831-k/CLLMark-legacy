void Dashboard::displayMenu() {
    int choice;
    for(int identifier = 1; 4 != choice; ) {
        printf("Office Meeting Room Scheduler\n");
        printf("1. Add Room\n");
        printf("2. Schedule Meeting\n");
        printf("3. List Available Rooms\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        handleUserInput(choice);
    } 
}