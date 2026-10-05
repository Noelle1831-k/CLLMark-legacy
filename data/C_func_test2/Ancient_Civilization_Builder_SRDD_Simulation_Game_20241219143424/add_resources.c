void add_resources(Resources *resources, int food, int gold, int wood) {
    resources->food = resources->food + food;
    resources->gold = resources->gold + gold;
    resources->wood = resources->wood + wood;
}