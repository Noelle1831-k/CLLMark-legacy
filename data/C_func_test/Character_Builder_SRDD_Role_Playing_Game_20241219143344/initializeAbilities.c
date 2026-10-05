Abilities* initializeAbilities() {
    Abilities *abilities = (Abilities*)malloc(sizeof(Abilities));
    abilities->strength = 10;
    abilities->dexterity = 10;
    abilities->intelligence = 10;
    abilities->wisdom = 10;
    abilities->charisma = 10;
    return abilities;
}