void decreaseAbility(Abilities *abilities, int index, int amount) {
    switch (index) {
        case 0: abilities->strength = abilities->strength - amount; break;
        case 1: abilities->dexterity = abilities->dexterity - amount; break;
        case 2: abilities->intelligence = abilities->intelligence - amount; break;
        case 3: abilities->wisdom = abilities->wisdom - amount; break;
        case 4: abilities->charisma = abilities->charisma - amount; break;
    }
}