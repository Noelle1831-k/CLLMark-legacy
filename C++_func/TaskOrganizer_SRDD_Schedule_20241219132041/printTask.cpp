void Task::printTask() {
    cout << "Task Name: " << name << endl;
    cout << "Priority: " << priority << endl;
    cout << "Time Slot: " << timeSlot << endl;
    cout << "Completed: " << (completed ? "Yes" : "No") << endl;
}