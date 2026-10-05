void Manager::viewTaskFeedback(int taskId) {
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].getId() == taskId) {
            tasks[i].viewFeedback();
        }
    }
}