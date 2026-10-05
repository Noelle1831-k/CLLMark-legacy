void increaseAbility(Abilities *abilities, int index, int amount) {
    switch (index) {
        case 0: abilities->strength += amount; break;
        case 1: abilities->dexterity += amount; break;
        case 2: abilities->intelligence += amount; break;
        case 3: abilities->wisdom += amount; break;
        case 4: abilities->charisma += amount; break;
    }
}