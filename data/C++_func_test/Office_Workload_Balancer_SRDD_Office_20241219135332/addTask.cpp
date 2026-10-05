void WorkloadManager::addTask(int taskId, const string& taskName, const string& requiredExpertise, int estimatedHours) {
    tasks.emplace_back(taskId, taskName, requiredExpertise, estimatedHours);
}