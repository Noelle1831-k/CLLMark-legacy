void Task::displayTaskDetails() const {
    cout << "Task ID: " << id << ", Name: " << name << ", Category: " << category
         << ", Deadline: " << deadline << ", Time Spent: " << timeSpent
         << ", Completed: " << (isCompleted ? "Yes" : "No") << endl;
}