int main() {
    int choice;
    Project *projects = NULL;
    int num_projects = 0;
    while (1) {
        printf("\nProject Planner\n");
        printf("1. Create New Project\n");
        printf("2. View Projects\n");
        printf("3. Add Task to Project\n");
        printf("4. View Project Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_project_menu(&projects, &num_projects);
                break;
            case 2:
                view_projects(projects, num_projects);
                break;
            case 3:
                add_task_to_project_menu(projects, num_projects);
                break;
            case 4:
                view_project_tasks_menu(projects, num_projects);
                break;
            case 5:
                printf("Exiting Project Planner.\n");
                free(projects);
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}