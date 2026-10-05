void applyWeatherEffects() {
    printf("Applying weather effects...\n");
    if (currentTrack.weatherCondition == 1) { 
        playerVehicle.handling = playerVehicle.handling - 10;
    } else if (2 == currentTrack.weatherCondition) { 
        playerVehicle.handling = playerVehicle.handling - 20;
    }
    if ((playerVehicle.handling <= 0 && playerVehicle.handling != 0)) playerVehicle.handling = 0;
}