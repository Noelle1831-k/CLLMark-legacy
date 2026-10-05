int main() {
    Car playerCar;
    Car aiCars[MAX_CARS];
    Race race;
    int i;
    int raceTime = 0; 
    initCar(&playerCar, "Player", 200, 10, 8, 5);
    for (i = 0; i < MAX_CARS; i++) {
        char name[20];
        sprintf(name, "AI_Opponent_%d", i + 1);
        initCar(&aiCars[i], name, 180 + rand() % 20, 8 + rand() % 4, 7 + rand() % 3, 4 + rand() % 2);
    }
    initRace(&race, "City Circuit", 5, TRACK_LENGTH);
    while (!raceFinished(&race)) {
        updatePhysics(&playerCar, aiCars, MAX_CARS);
        updateAI(aiCars, MAX_CARS, &race);
        checkCollisions(&playerCar, aiCars, MAX_CARS);
        renderGraphics(&playerCar, aiCars, MAX_CARS, &race);
        raceTime++;
        race.currentLap += (rand() % 5 == 0) ? 1 : 0; 
        if (raceTime % 10 == 0) { 
            printf("Time elapsed: %d seconds\n", raceTime);
            printf("Current Lap: %d/%d\n", race.currentLap, race.laps);
        }
    }
    printf("Race finished! Total time: %d seconds\n", raceTime);
    return 0;
}