void Task::displayTask() const {
    cout << "ID: " << id << "\nTitle: " << title << "\nDescription: " << description
         << "\nDeadline: " << deadline << "\nPriority: " << priority
         << "\nStatus: " << status << "\nCategory: " << category << "\n";
}