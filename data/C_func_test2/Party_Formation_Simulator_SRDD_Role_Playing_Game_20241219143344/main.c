int main() {
    printf("Welcome to the RPG Party Formation Simulator!\n");
    printf("=============================================\n");
    Character *characters = NULL;
    int numCharacters = 0;
    Party optimalParty = {NULL, 0};
    int option;
    while (1) {
        showMenu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                if (characters != NULL) {
                    free(characters);
                }
                printf("Enter the number of characters to create: ");
                scanf("%d", &numCharacters);
                characters = (Character *)malloc(numCharacters * sizeof(Character));
                if (!characters) {
                    fprintf(stderr, "Memory allocation failed for characters.\n");
                    return 1;
                }
                for (int i = 0; i < numCharacters; i++) {
                    printf("\nCreating character %d:\n", i + 1);
                    characters[i] = createCharacter();
                }
                break;
            case 2:
                if (characters == NULL) {
                    printf("No characters created yet. Please create characters first.\n");
                } else {
                    printf("\nDisplaying all characters:\n");
                    for (int i = 0; i < numCharacters; i++) {
                        printf("\nCharacter %d:\n", i + 1);
                        displayCharacter(characters[i]);
                    }
                }
                break;
            case 3:
                if (characters == NULL) {
                    printf("No characters created yet. Please create characters first.\n");
                } else {
                    printf("\nGenerating optimal party formation...\n");
                    if (optimalParty.members != NULL) {
                        freeParty(optimalParty);
                    }
                    optimalParty = generateOptimalParty(characters, numCharacters);
                    printf("\nOptimal Party Composition:\n");
                    displayParty(optimalParty);
                }
                break;
            case 4:
                if (optimalParty.members == NULL) {
                    printf("No optimal party generated yet. Please generate a party first.\n");
                } else {
                    printf("\nVisualizing party composition...\n");
                    visualizeParty(optimalParty);
                }
                break;
            case 5:
                printf("Exiting the program. Thank you for using the RPG Party Formation Simulator!\n");
                free(characters);
                freeParty(optimalParty);
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}