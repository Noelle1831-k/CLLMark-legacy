void train_pet() {
    if (myPet.energy < 10) {
        printf("%s is too tired to train. Let them rest first.\n", myPet.name);
        return;
    }
    printf("Training %s...\n", myPet.name);
    myPet.strength += rand() % 5;
    myPet.agility += rand() % 5;
    myPet.intelligence += rand() % 5;
    myPet.happiness -= 5;
    myPet.energy -= 10;
    printf("Training complete!\n");
    display_pet_stats();
}