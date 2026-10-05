void Schedule::displayTasks() {
    cout << "====== All Tasks ======\n";
    for (auto &task : tasks) {
        task.displayTask();
    }
}