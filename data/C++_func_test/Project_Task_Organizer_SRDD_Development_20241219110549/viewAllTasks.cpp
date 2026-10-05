void Dashboard::viewAllTasks() {
    for (auto& project : projects) {
        project.displayTasks();
    }
}