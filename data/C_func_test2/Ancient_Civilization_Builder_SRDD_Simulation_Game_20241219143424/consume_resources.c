void consume_resources(Resources *resources, int food, int gold, int wood) {
    resources->food -= food;
    resources->gold -= gold;
    resources->wood -= wood;
}