void trackProgress() {
    printf("Tracking user progress...\n");
    printf("Current progress: %d%%\n", userProgress);
    userProgress += 10; 
    if (userProgress >= 100) {
        printf("Congratulations! You have reached your goal!\n");
        userProgress = 0; 
    }
}