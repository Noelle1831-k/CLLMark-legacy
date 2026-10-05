int main() {
    int choice;
    Character character;
    initializeCharacter(&character);
    while (1) {
        displayMenu();
        choice = getValidatedInput(1, 7);
        switch (choice) {
            case 1:
                createCharacter(&character);
                break;
            case 2:
                customizeCharacter(&character);
                break;
            case 3:
                addSkills(&character);
                break;
            case 4:
                displayCharacter(&character);
                break;
            case 5:
                saveCharacterToFile(&character);
                break;
            case 6:
                loadCharacterFromFile(&character);
                break;
            case 7:
                printf("Exiting Skill Planner. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}