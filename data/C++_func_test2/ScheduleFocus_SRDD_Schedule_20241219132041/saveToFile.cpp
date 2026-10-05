void Scheduler::saveToFile() const {
    ofstream outFile("schedule.txt");
    if (!outFile) {
        cout << "Error opening file for saving.\n";
        return;
    }
    for (const auto& task : tasks) {
        outFile << task.getID() << "|" << task.getName() << "|" << task.getStartTime() << "|" << task.getEndTime() << "|" << task.getPriority() << "\n";
    }
    outFile.close();
    cout << "Schedule saved successfully!\n";
}