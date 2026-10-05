void FeedbackSystem::addTask(int id, string name) {
    Task newTask(id, name);
    tasks.push_back(newTask);
}