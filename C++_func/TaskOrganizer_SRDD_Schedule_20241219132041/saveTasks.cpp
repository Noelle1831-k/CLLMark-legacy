void FileHandler::saveTasks(vector<Task> tasks) {
    ofstream file("tasks.txt");
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    for (const auto &task : tasks) {
        file << task.getName() << "," << task.getPriority() << "," << task.getTimeSlot() << "," << task.getCompleted() << endl;
    }
    file.close();
}