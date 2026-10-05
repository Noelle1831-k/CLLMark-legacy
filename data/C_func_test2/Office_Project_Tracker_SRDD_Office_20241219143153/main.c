int main() {
    int choice;
    ProjectList *project_list = NULL;
    initialize_system();
    project_list = load_data();
    if (project_list == NULL) {
        fprintf(stderr, "Error: Failed to load data.\n");
        return EXIT_FAILURE;
    }
    while (1) {
        display_dashboard();
        choice = get_input();
        switch (choice) {
            case 1:
                add_project(project_list);
                break;
            case 2:
                update_project(project_list);
                break;
            case 3:
                remove_project(project_list);
                break;
            case 4:
                list_projects(project_list);
                break;
            case 5:
                save_data(project_list);
                printf("Exiting the application...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}