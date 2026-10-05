void update_animal_health(Animal* animal) {
    printf("Enter new health status: ");
    scanf("%s", animal->health_status);
    printf("Health status updated.\n");
}