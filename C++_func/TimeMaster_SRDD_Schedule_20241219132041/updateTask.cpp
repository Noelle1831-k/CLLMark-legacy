void Schedule::updateTask(string name, string newName, int newPriority, string newTimeSlot, int newProgress) {
    Task* task = findTask(name);
    if (task != nullptr) {
        task->updateTaskDetails(newName, newPriority, newTimeSlot, newProgress);
        cout << "Task \"" << name << "\" updated successfully." << endl;
    } else {
        cout << "Task \"" << name << "\" not found." << endl;
    }
}