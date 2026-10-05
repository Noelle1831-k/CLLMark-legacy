int main() {
    printf("Welcome to the Character Development Planner!\n");
    Character *character = create_character();
    if (character == NULL) {
        fprintf(stderr, "Failed to create character.\n");
        return EXIT_FAILURE;
    }
    input_character_attributes(character);
    input_character_skills(character);
    ProgressionPlan *plan = generate_progression_plan(character);
    if (plan == NULL) {
        fprintf(stderr, "Failed to generate progression plan.\n");
        free_character(character);
        return EXIT_FAILURE;
    }
    display_progression_plan(plan);
    visualize_character(character);
    free_progression_plan(plan);
    free_character(character);
    return EXIT_SUCCESS;
}