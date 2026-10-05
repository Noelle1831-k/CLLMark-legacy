void perform_activity() {
    if (currentActivity.difficulty > myPet.energy) {
        printf("%s is too tired to perform this activity.\n", myPet.name);
        return;
    }
    printf("Performing activity: %s\n", currentActivity.activity_name);
    myPet.strength = myPet.strength + currentActivity.difficulty;
    myPet.agility = myPet.agility + currentActivity.difficulty;
    myPet.energy = myPet.energy - currentActivity.difficulty;
    printf("Activity complete!\n");
    display_pet_stats();
}