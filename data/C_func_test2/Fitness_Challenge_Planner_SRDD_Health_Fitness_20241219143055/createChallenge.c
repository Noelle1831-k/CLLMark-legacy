void createChallenge() {
    char *name = (char*)malloc(sizeof(char) * 100);
    char *goal = (char*)malloc(sizeof(char) * 50);
    int duration, intensity;
    printf("\nEnter Challenge Name: ");
    getInputString(name, sizeof(name));
    printf("Enter Goal (Weight Loss, Muscle Gain, Endurance): ");
    getInputString(goal, sizeof(goal));
    duration = getInput("Enter Duration in Days: ");
    intensity = getInput("Enter Intensity (1-10): ");
    Challenge newChallenge;
    strcpy(newChallenge.name, name);
    strcpy(newChallenge.goal, goal);
    newChallenge.duration = duration;
    newChallenge.intensity = intensity;
    newChallenge.progress = 0;
    saveChallenge(newChallenge);
    printf("Challenge \"%s\" created successfully!\n", newChallenge.name);
}