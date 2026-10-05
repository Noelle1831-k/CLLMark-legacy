void applyWeatherEffects() {
    printf("Applying weather effects...\n");
    if (currentTrack.weatherCondition == 1) { 
        playerVehicle.handling -= 10;
    } else if (currentTrack.weatherCondition == 2) { 
        playerVehicle.handling -= 20;
    }
    if (playerVehicle.handling < 0) playerVehicle.handling = 0;
}