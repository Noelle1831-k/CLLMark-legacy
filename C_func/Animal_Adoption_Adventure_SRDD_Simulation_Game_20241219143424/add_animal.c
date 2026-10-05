void add_animal(Animal animals[], int* count) {
    if (*count >= MAX_ANIMALS) {
        printf("Animal center is full!\n");
        return;
    }
    Animal new_animal;
    printf("Enter animal name: ");
    scanf("%s", new_animal.name);
    printf("Enter animal age: ");
    scanf("%d", &new_animal.age);
    strcpy(new_animal.health_status, "Healthy");
    new_animal.adoption_status = 0;
    animals[*count] = new_animal;
    (*count)++;
    printf("Animal added successfully!\n");
}