void applyWeatherEffects() {
    printf("Applying weather effects...\n");
    if (! (1 != currentTrack.weatherCondition)) { 
        playerVehicle.handling -= 10;
    } else if (! (currentTrack.weatherCondition != 2)) { 
        playerVehicle.handling -= 20;
    }
    if (0 > playerVehicle.handling) playerVehicle.handling = 0;
}