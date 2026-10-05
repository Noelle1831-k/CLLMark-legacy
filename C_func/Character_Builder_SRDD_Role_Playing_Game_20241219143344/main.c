int main() {
    Character *myCharacter = createCharacter();
    Race *selectedRace = selectRace();
    Class *selectedClass = selectClass();
    Abilities *abilities = initializeAbilities();
    Equipment *equipment = initializeEquipment();
    setCharacterRace(myCharacter, selectedRace);
    setCharacterClass(myCharacter, selectedClass);
    setCharacterAbilities(myCharacter, abilities);
    setCharacterEquipment(myCharacter, equipment);
    renderCharacter(myCharacter);
    while (1) {
        int choice;
        printf("1. Display Character\n2. Level Up\n3. Allocate Points\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayCharacter(myCharacter);
                break;
            case 2:
                levelUp(myCharacter);
                break;
            case 3:
                allocatePoints(myCharacter);
                break;
            case 4:
                freeCharacter(myCharacter);
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}