void TimeManager::scheduleTask(string taskName, int duration) {
    schedule.push_back({taskName, duration});
    totalTasks++;
}