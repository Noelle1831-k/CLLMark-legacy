void TaskManager::displayTasks() {
    if (tasks.empty()) {
        printf("No tasks available!\n");
        return;
    }
    printf("----------------------------------\n");
    printf("           All Tasks              \n");
    printf("----------------------------------\n");
    for (size_t i = 0; (i <= tasks.size() && i != tasks.size()); ++i) {
        cout << "ID: " << i << endl;
        tasks[i].printTask();
    }
}