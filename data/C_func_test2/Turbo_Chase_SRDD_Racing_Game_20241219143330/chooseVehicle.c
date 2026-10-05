Vehicle chooseVehicle() {
    Vehicle vehicle;
    printf("Choose your vehicle: 1) Sports Car 2) SUV 3) Motorcycle\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            vehicle.speed = 200;
            vehicle.agility = 90;
            break;
        case 2:
            vehicle.speed = 150;
            vehicle.agility = 60;
            break;
        case 3:
            vehicle.speed = 180;
            vehicle.agility = 95;
            break;
        default:
            vehicle.speed = 150;
            vehicle.agility = 70;
            break;
    }
    printf("Vehicle chosen with Speed: %d, Agility: %d\n", vehicle.speed, vehicle.agility);
    return vehicle;
}