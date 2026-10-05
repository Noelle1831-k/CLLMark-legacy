int has_sufficient_resources(Resources *resources, int food, int gold, int wood) {
    return resources->food >= food && resources->gold >= gold && resources->wood >= wood;
}