void Task::getTaskDetails() const {
    cout << "Task: " << description << endl;
    cout << "Status: " << (isComplete ? "Complete" : "Incomplete") << endl;
}