void Task::inputDetails() {
    printf("Enter task name: ");
    cin.ignore();
    getline(cin, name);
    printf("Enter task description: ");
    getline(cin, description);
    printf("Enter task deadline: ");
    getline(cin, deadline);
    printf("Enter task category: ");
    getline(cin, category);
}