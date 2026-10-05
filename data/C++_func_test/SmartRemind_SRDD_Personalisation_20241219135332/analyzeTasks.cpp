void UserAnalyzer::analyzeTasks(TaskManager& taskManager) {
    vector<Task> tasks = taskManager.getTasks();
    for (vector<Task>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
        int newPriority = Algorithm::calculatePriority(it->getDueDate());
        if (newPriority != it->getPriority()) {
            cout << "Updating priority for task: " << it->getName() 
                 << " from " << it->getPriority() 
                 << " to " << newPriority << endl;
            it->setPriority(newPriority);
        }
    }
}