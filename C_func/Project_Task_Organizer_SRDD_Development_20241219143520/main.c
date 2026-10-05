int main() {
    Project *project = initializeProject("Default Project", "Project Manager");
    int choice;
    char buffer[100];
    while (1) {
        showDashboard();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1: {
                printf("\nEnter Task Name: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0; 
                Task *newTask = initializeTask(buffer, "Description", "Unassigned", "Pending");
                addTaskToProject(project, newTask);
                printf("Task '%s' created successfully!\n", buffer);
                break;
            }
            case 2: {
                printf("Enter Task Name: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                printf("Enter Description: ");
                char description[100];
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0;
                Task *task = initializeTask(buffer, description, "Unassigned", "Pending");
                addTaskToProject(project, task);
                printf("Task '%s' added to project successfully!\n", buffer);
                break;
            }
            case 3: {
                printf("Enter Task Index to Assign: ");
                int index;
                scanf("%d", &index);
                getchar();
                if (index > 0 && index <= project->taskCount) {
                    printf("Enter User Name: ");
                    fgets(buffer, sizeof(buffer), stdin);
                    buffer[strcspn(buffer, "\n")] = 0;
                    assignTaskToUser(project->tasks[index - 1], buffer);
                    printf("Task assigned to %s successfully!\n", buffer);
                } else {
                    printf("Invalid Task Index.\n");
                }
                break;
            }
            case 4: {
                printf("Enter Task Index to Update: ");
                int index;
                scanf("%d", &index);
                getchar();
                if (index > 0 && index <= project->taskCount) {
                    printf("Enter New Status: ");
                    fgets(buffer, sizeof(buffer), stdin);
                    buffer[strcspn(buffer, "\n")] = 0;
                    updateTaskStatus(project->tasks[index - 1], buffer);
                    printf("Task status updated to '%s'.\n", buffer);
                } else {
                    printf("Invalid Task Index.\n");
                }
                break;
            }
            case 5: {
                displayProjectTasks(project);
                break;
            }
            case 6: {
                saveDataToFile(project, "data.txt");
                printf("Data saved successfully.\n");
                break;
            }
            case 7: {
                loadDataFromFile(project, "data.txt");
                printf("Data loaded successfully.\n");
                break;
            }
            case 8: {
                printf("Exiting program...\n");
                return 0;
            }
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}