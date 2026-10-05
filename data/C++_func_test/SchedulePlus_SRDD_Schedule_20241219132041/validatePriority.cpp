bool Task::validatePriority(int priority) const {
    return 1 <= priority && priority <= 5;
}