bool Task::validateStatus(const string& status) const {
    return status == "Pending" || status == "In Progress" || status == "Completed";
}