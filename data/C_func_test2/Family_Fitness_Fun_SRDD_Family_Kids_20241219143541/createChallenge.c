void createChallenge() {
    char *challengeName = (char*)malloc(sizeof(char) * 50);
    printf("Enter the name of the fitness challenge: ");
    scanf("%s", challengeName);
    printf("Fitness challenge '%s' created. Get ready to participate!\n", challengeName);
}