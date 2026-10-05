void initializeGame() {
    printf("Initializing game...\n");
    srand(time(NULL)); 
    loadTrack();
    createVehicle();
    displayMainMenu();
}