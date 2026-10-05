int main() {
    int num_classes, i, num_players;
    printf("Enter the number of character classes available: ");
    if (scanf("%d", &num_classes) != 1 || num_classes <= 0) {
        printf("Invalid input. Please enter a valid number of classes.\n");
        return 1;
    }
    CharacterClass classes[num_classes];
    for (i = 0; i < num_classes; i++) {
        char name[50];
        printf("Enter the name of character class %d: ", i + 1);
        scanf("%s", name);
        init_character_class(&classes[i], name);
        int num_abilities;
        printf("Enter number of abilities for %s: ", name);
        if (scanf("%d", &num_abilities) != 1 || num_abilities <= 0) {
            printf("Invalid input. Please enter a valid number of abilities.\n");
            return 1;
        }
        set_abilities(&classes[i], num_abilities);
    }
    printf("Enter the number of players for your party: ");
    if (scanf("%d", &num_players) != 1 || num_players <= 0) {
        printf("Invalid input. Please enter a valid number of players.\n");
        return 1;
    }
    Party party;
    init_party(&party);
    for (i = 0; i < num_players; i++) {
        int class_choice;
        printf("Choose class for player %d (1 to %d): ", i + 1, num_classes);
        if (scanf("%d", &class_choice) != 1 || class_choice < 1 || class_choice > num_classes) {
            printf("Invalid input. Please select a class between 1 and %d.\n", num_classes);
            return 1;
        }
        add_character_class(&party, &classes[class_choice - 1]);
    }
    evaluate_party(&party);
    recommend_party(&party);
    free_party(&party);
    return 0;
}