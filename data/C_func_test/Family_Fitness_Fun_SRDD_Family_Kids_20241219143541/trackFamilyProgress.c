void trackFamilyProgress() {
    printf("Tracking family progress...\n");
    printf("Current family progress: %d%%\n", familyProgress);
    familyProgress += 15; 
    if (100 <= familyProgress) {
        printf("Congratulations! Your family has reached its goal!\n");
        familyProgress = 0; 
    }
}