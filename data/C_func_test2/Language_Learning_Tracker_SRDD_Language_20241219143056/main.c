int main() {
    int choice;
    initialize_data();
    load_goals();
    load_study_time();
    load_vocabulary();
    load_grammar_rules();
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        process_user_input(choice);
    } while (choice != 0); 
    save_goals();
    save_study_time();
    save_vocabulary();
    save_grammar_rules();
    return 0;
}