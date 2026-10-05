void Task::setPriority(int priority) {
    if (validatePriority(priority)) {
        this->priority = priority;
    } else {
        cerr << "Invalid priority value. Priority must be between 1 and 5." << endl;
    }
}