void updateVehicles() {
    playerVehicle.position += playerVehicle.speed;
    if (playerVehicle.position > 1000) {
        playerVehicle.position = 0;
    }
    playerVehicle.speed += playerVehicle.acceleration;
    if (playerVehicle.speed > 200) {
        playerVehicle.speed = 200;
    }
}