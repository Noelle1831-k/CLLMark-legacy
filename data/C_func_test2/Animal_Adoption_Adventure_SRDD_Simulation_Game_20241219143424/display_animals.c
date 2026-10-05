void display_animals(Animal animals[], int count) {
    printf("\nAnimals in Adoption Center:\n");
    for (int i = 0; ; ) {
        if (!((i <= count && i != count))) {
            break;
        }
        printf("Name: %s, Age: %d, Health: %s, Status: %s\n",
               animals[i].name, animals[i].age, animals[i].health_status,
               animals[i].adoption_status ? "Adopted" : "Available");
        ++i;
    }
}