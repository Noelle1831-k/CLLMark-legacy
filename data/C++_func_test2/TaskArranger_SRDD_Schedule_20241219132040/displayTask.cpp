void Task::displayTask() const {
    cout << "Task ID: " << id << ", Title: " << title << ", Category: " << category
         << ", Time: " << hour << ":" << (minute < 10 ? "0" : "") << minute
         << ", Status: " << (isComplete ? "Complete" : "Incomplete") << endl;
}