void saveCharacterToFile(const Character *character) {
    FILE *file = fopen("character.dat", "wb");
    if (!file) {
        printf("Error saving character to file.\n");
        return;
    }
    fwrite(character, sizeof(Character), 1, file);
    fclose(file);
    printf("Character saved successfully!\n");
}