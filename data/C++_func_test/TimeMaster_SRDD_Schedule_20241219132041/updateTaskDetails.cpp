void Task::updateTaskDetails(string newName, int newPriority, string newTimeSlot, int newProgress) {
    name = newName;
    priority = newPriority;
    timeSlot = newTimeSlot;
    setProgress(newProgress);
}