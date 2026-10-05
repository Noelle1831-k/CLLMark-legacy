void calculatePhysics() {
    printf("Calculating physics...\n");
    int speedAdjustment = currentTrack.difficulty * 5;
    playerVehicle.speed -= speedAdjustment;
    if (playerVehicle.speed < 0) playerVehicle.speed = 0;
}