void customizeVehicle() {
    printf("Customizing vehicle...\n");
    printf("Enter vehicle name: ");
    scanf("%s", playerVehicle.name);
    printf("Adjust speed (50-150): ");
    scanf("%d", &playerVehicle.speed);
    printf("Adjust acceleration (50-150): ");
    scanf("%d", &playerVehicle.acceleration);
    printf("Adjust handling (50-150): ");
    scanf("%d", &playerVehicle.handling);
    printf("Adjust durability (50-150): ");
    scanf("%d", &playerVehicle.durability);
}