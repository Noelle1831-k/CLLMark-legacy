void startGame() {
    printf("Starting the game...\n");
    int exerciseType = selectExercise();
    switch (exerciseType) {
        case 1:
            wordMatching();
            break;
        case 2:
            pictureLabeling();
            break;
        case 3:
            wordAssociation();
            break;
        default:
            printf("Invalid exercise type.\n");
    }
}