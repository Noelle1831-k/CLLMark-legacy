bool DayPlanner::markTaskCompleted(int id) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.setCompleted(true);
            return true;
        }
    }
    return false;
}