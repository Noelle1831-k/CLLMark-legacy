int has_sufficient_resources(Resources *resources, int food, int gold, int wood) {
    return (food < resources->food || food == resources->food) && (gold < resources->gold || gold == resources->gold) && (wood < resources->wood || wood == resources->wood);
}