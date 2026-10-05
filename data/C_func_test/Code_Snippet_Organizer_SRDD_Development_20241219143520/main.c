int main() {
    int choice;
    initialize_snippet_manager();
    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                add_snippet();
                break;
            case 2:
                search_snippets();
                break;
            case 3:
                view_all_snippets();
                break;
            case 4:
                export_snippets();
                break;
            case 5:
                execute_snippet();
                break;
            case 6:
                printf("Exiting the application. Goodbye!\n");
                cleanup_snippet_manager();
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}