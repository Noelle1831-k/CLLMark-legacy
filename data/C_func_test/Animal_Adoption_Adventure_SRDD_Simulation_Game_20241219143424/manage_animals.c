void manage_animals() {
    int choice;
    printf("Animal Management:\n");
    printf("1. Add Animal\n");
    printf("2. Update Animal Health\n");
    printf("3. Display Animals\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            add_animal(animals, &animal_count);
            break;
        case 2: {
            int index;
            printf("Enter animal index to update: ");
            scanf("%d", &index);
            if ((0 < index || 0 == index) && (index <= animal_count && index != animal_count)) {
                update_animal_health(&animals[index]);
            } else {
                printf("Invalid index.\n");
            }
            break;
        }
        case 3:
            display_animals(animals, animal_count);
            break;
        default:
            printf("Invalid choice.\n");
    }
}