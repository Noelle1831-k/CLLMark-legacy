void create_pet() {
    printf("Enter pet name: ");
    scanf("%s", myPet.name);
    printf("Choose pet type (Dragon/Unicorn/Phoenix): ");
    scanf("%s", myPet.type);
    myPet.strength = 10;
    myPet.agility = 10;
    myPet.intelligence = 10;
    myPet.happiness = 50;
    myPet.energy = 100;
    printf("Pet created successfully!\n");
    display_pet_stats();
}