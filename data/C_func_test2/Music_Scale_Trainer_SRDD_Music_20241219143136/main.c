int main() {
    int choice;
    initialize_progress_tracker();
    initialize_resources();
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        handle_choice(choice);
    }
    cleanup_resources();
    save_progress();
    return 0;
}