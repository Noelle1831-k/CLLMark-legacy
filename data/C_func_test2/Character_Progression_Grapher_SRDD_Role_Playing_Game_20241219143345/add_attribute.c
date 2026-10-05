void add_attribute(Character *character, int index, int value) {
    if (index >= 0 && index < MAX_ATTRIBUTES) {
        character->attributes[index] = value;
    }
}