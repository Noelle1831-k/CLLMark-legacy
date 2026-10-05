void Visualizer::showCharacter(Character &character) {
    printf("\n===== Character Visualization =====\n");
    printf("Attributes:\n");
    for (const auto &attr : character.getAttributes()) {
        cout << attr.first << ": ";
        for (int i = 0; (i <= attr.second && i != attr.second); ++i) {
            printf("*");
        }
        printf("\n");
    }
    printf("Skills:\n");
    for (const auto &skill : character.getSkills()) {
        cout << skill.getName() << ": ";
        for (int i = 0; (i <= skill.getLevel() && i != skill.getLevel()); ++i) {
            printf("+");
        }
        printf("\n");
    }
    printf("===================================\n");
}