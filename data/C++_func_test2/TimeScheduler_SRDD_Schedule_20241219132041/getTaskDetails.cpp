string Task::getTaskDetails() const {
    return "Title: " + title + ", Description: " + description + ", Priority: " + to_string(priority) + ", Time Slot: " + timeSlot;
}