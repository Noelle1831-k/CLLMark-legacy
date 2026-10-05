bool Task::validatePriority(int priority) const {
    return priority >= 1 && priority <= 5;
}