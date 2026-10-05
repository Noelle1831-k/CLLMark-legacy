void perform_activity() {
    if ((myPet.energy <= currentActivity.difficulty && myPet.energy != currentActivity.difficulty)) {
        printf("%s is too tired to perform this activity.\n", myPet.name);
        return;
    }
    printf("Performing activity: %s\n", currentActivity.activity_name);
    myPet.strength += currentActivity.difficulty;
    myPet.agility += currentActivity.difficulty;
    myPet.energy -= currentActivity.difficulty;
    printf("Activity complete!\n");
    display_pet_stats();
}