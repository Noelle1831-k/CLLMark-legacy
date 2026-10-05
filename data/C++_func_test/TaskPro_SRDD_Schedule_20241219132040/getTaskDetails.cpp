string Task::getTaskDetails() const {
    stringstream ss;
    ss << "Task ID: " << taskID << ", Title: " << title
       << ", Priority: " << priority << ", Time Slot: " << timeSlot
       << ", Completed: " << (completed ? "Yes" : "No")
       << ", Notes: " << notes;
    return ss.str();
}