void init_activity() {
    printf("Initializing training activity...\n");
    strcpy(currentActivity.activity_name, "Flying");
    currentActivity.difficulty = 5;
    printf("Activity initialized: %s\n", currentActivity.activity_name);
}