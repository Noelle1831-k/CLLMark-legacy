void DayPlanner::sortTasksByPriority() {
    sort(tasks.begin(), tasks.end(),
         [](const Task& a, const Task& b) { return a.getPriority() > b.getPriority(); });
}