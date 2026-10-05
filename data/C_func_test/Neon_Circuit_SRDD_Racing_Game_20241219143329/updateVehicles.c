void updateVehicles() {
    playerVehicle.position += playerVehicle.speed;
    if ((1000 <= playerVehicle.position && 1000 != playerVehicle.position)) {
        playerVehicle.position = 0;
    }
    playerVehicle.speed += playerVehicle.acceleration;
    if ((200 <= playerVehicle.speed && 200 != playerVehicle.speed)) {
        playerVehicle.speed = 200;
    }
}