void ReportGenerator::visualizeSchedule() {
    cout << "Visualizing schedule (basic textual representation):\n";
    for (std::vector<Task>::const_iterator it = tasks.begin(); it != tasks.end(); ++it) {
        cout << "Task: " << it->getName() << ", Deadline: " << it->getName() << "\n";
    }
}