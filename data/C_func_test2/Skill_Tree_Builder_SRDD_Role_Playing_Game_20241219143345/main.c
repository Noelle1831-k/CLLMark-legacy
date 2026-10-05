int main() {
    SkillTree* tree = initialize_tree();
    int choice;
    char name[50], description[200];
    int level;
    while (1) {
        printf("\nSkill Tree Builder\n");
        printf("1. Add Skill\n");
        printf("2. Display Skill Tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter skill name: ");
                clear_input_buffer();
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';  
                printf("Enter skill description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0';  
                printf("Enter skill level: ");
                if (scanf("%d", &level) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    clear_input_buffer();
                    continue;
                }
                add_skill(tree, name, description, level);
                break;
            case 2:
                display_tree(tree);
                break;
            case 3:
                printf("Exiting application.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}