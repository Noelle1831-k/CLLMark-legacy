void loadCharacterFromFile(Character *character) {
    FILE *file = fopen("character.dat", "rb");
    if (!file) {
        printf("Error loading character from file.\n");
        return;
    }
    fread(character, sizeof(Character), 1, file);
    fclose(file);
    printf("Character loaded successfully!\n");
}