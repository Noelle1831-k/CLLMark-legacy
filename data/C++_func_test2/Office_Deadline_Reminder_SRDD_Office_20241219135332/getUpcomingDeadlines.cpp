vector<Task> TaskManager::getUpcomingDeadlines() {
    vector<Task> upcomingTasks;
    time_t now = time(0);
    for (vector<Task>::iterator it = taskList.begin(); it != taskList.end(); ++it) {
        if (difftime(it->getDeadline(), now) > 0) {
            upcomingTasks.push_back(*it);
        }
    }
    return upcomingTasks;
}