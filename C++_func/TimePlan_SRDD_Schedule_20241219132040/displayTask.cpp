void Task::displayTask() const {
    cout << "Task ID: " << id << "\nTitle: " << title << "\nDescription: " << description
         << "\nDeadline: " << deadline << "\nStatus: " << status
         << "\nTime Allocated: " << timeAllocated << " hours\n" << endl;
}