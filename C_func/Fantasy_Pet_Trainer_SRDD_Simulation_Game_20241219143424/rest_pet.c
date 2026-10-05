void rest_pet() {
    printf("%s is resting...\n", myPet.name);
    myPet.energy += 30;
    if (myPet.energy > 100) myPet.energy = 100;
    printf("Resting complete!\n");
    display_pet_stats();
}