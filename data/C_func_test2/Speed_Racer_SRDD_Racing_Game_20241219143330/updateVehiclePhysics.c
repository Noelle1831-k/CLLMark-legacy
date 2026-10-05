void updateVehiclePhysics() {
    printf("Updating vehicle physics...\n");
    playerVehicle.durability = playerVehicle.durability - 1;
    if (playerVehicle.durability < 0) playerVehicle.durability = 0;
}