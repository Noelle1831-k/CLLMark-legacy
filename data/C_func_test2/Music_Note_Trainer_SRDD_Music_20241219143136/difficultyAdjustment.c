void difficultyAdjustment(int level) {
    switch(level) {
        case 1:
            printf("Difficulty set to Easy: Only single notes.\n");
            break;
        case 2:
            printf("Difficulty set to Medium: Includes intervals and note identification.\n");
            break;
        case 3:
            printf("Difficulty set to Hard: Includes complex intervals and higher speed.\n");
            break;
        default:
            printf("Invalid difficulty level.\n");
            break;
    }
}