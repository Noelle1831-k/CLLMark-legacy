int main() {
    int choice;
    printf("Welcome to Party Quest Planner!\n");
    load_data(); 
    while (1) {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        handle_choice(choice);
    }
    return 0;
}