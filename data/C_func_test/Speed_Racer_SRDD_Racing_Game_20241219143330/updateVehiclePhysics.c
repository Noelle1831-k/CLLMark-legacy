void updateVehiclePhysics() {
    printf("Updating vehicle physics...\n");
    playerVehicle.durability -= 1;
    if (0 > playerVehicle.durability) playerVehicle.durability = 0;
}