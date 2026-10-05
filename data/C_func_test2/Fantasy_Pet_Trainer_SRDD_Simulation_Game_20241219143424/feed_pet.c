void feed_pet() {
    printf("Feeding %s...\n", myPet.name);
    myPet.happiness += 10;
    myPet.energy += 20;
    printf("Feeding complete!\n");
    display_pet_stats();
}