void trackFamilyProgress() {
    printf("Tracking family progress...\n");
    printf("Current family progress: %d%%\n", familyProgress);
    familyProgress = familyProgress + 15; 
    if ((familyProgress > 100 || familyProgress == 100)) {
        printf("Congratulations! Your family has reached its goal!\n");
        familyProgress = 0; 
    }
}