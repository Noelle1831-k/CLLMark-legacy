void initializeApp() {
    printf("Initializing Music Note Trainer...\n");
    srand(time(NULL)); 
    loadUserData();
    setDifficultyLevel(1); 
}