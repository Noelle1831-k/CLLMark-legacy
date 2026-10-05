bool DayPlanner::deleteTask(int id) {
    auto it = remove_if(tasks.begin(), tasks.end(),
                        [id](const Task& task) { return task.getId() == id; });
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        return true;
    }
    return false;
}