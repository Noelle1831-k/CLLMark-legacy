void TaskManager::sortTasksByTime() {
    for (size_t i = 0; i < tasks.size(); ++i) {
        for (size_t j = i + 1; j < tasks.size(); ++j) {
            if ((tasks[i].getHour() * 60 + tasks[i].getMinute()) > (tasks[j].getHour() * 60 + tasks[j].getMinute())) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
    cout << "Tasks sorted by time.\n";
}