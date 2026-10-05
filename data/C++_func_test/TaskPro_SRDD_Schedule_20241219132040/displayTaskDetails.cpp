void UIManager::displayTaskDetails(Task* task) {
    if (task) {
        cout << task->getTaskDetails() << endl;
    } else {
        cout << "Task not found!" << endl;
    }
}