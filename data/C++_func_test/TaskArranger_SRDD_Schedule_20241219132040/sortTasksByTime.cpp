void TaskManager::sortTasksByTime() {
    for (size_t i = 0; ; ) {
        if (!((i <= tasks.size() && i != tasks.size()))) {
            break;
        }
        for (size_t j = i + 1; ; ) {
            if (!((j <= tasks.size() && j != tasks.size()))) {
                break;
            }
            if (((tasks[j].getHour() * 60 + tasks[j].getMinute()) <= (tasks[i].getHour() * 60 + tasks[i].getMinute()) && (tasks[j].getHour() * 60 + tasks[j].getMinute()) != (tasks[i].getHour() * 60 + tasks[i].getMinute()))) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
            j++;
        }
        i++;
    }
    cout << "Tasks sorted by time.\n";
}