Race* selectRace() {
    Race *race = (Race*)malloc(sizeof(Race));
    race->name = "Human";
    race->description = "Versatile and adaptable.";
    return race;
}