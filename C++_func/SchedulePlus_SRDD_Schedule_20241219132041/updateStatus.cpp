void Task::updateStatus(string status) {
    if (validateStatus(status)) {
        this->status = status;
    } else {
        cerr << "Invalid status value. Status must be 'Pending', 'In Progress', or 'Completed'." << endl;
    }
}