int main() {
    printf("=== RPG Quest Difficulty Analyzer ===\n");
    printf("Analyze the difficulty of your RPG quests with ease!\n");
    int enemy_strength, required_skill, time_constraint;
    char quest_name[MAX_INPUT];
    printf("Enter the quest name: ");
    if (fgets(quest_name, MAX_INPUT, stdin) == NULL) {
        printf("Error reading input. Defaulting quest name to 'unknown'.\n");
        strncpy(quest_name, "unknown", MAX_INPUT);
    }
    sanitize_input(quest_name);
    printf("Enter enemy strength (1-10): ");
    enemy_strength = validate_input(get_integer_input());
    printf("Enter required skill level (1-10): ");
    required_skill = validate_input(get_integer_input());
    printf("Enter time constraint in hours: ");
    time_constraint = validate_input(get_integer_input());
    Quest quest;
    strncpy(quest.name, quest_name, MAX_NAME_LENGTH);
    quest.enemy_strength = enemy_strength;
    quest.required_skill = required_skill;
    quest.time_constraint = time_constraint;
    double difficulty = calculate_difficulty(&quest);
    printf("The difficulty rating for quest '%s' is: %.2f\n", quest.name, difficulty);
    printf("Thank you for using the RPG Quest Difficulty Analyzer!\n");
    printf("Feel free to analyze more quests to optimize your gameplay.\n");
    return 0;
}