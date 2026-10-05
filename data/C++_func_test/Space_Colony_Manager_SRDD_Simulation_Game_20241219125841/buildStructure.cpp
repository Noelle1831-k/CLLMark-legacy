void Colony::buildStructure() {
    if (resources >= 100) {
        printf("Building a new structure...\n");
        resources = resources - 100;
        printf("Structure built successfully!\n");
    } else {
        printf("Not enough resources to build a structure.\n");
    }
}