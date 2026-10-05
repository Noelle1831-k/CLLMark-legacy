void sortCharactersByStrength(Character *characters, int numCharacters) {
    for (int i = 0; i < numCharacters - 1; i++) {
        for (int j = 0; j < numCharacters - i - 1; j++) {
            if (characters[j].strength < characters[j + 1].strength) {
                Character temp = characters[j];
                characters[j] = characters[j + 1];
                characters[j + 1] = temp;
            }
        }
    }
}