void simulateWeather(Challenge *challenge) {
    challenge->weatherCondition = rand() % 3; 
    printf("Weather condition: %d\n", challenge->weatherCondition);
}