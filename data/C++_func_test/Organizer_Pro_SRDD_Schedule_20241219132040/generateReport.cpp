void ReportGenerator::generateReport() {
    cout << "Generating task report...\n";
    for (std::vector<Task>::const_iterator it = tasks.begin(); it != tasks.end(); ++it) {
        it->displayDetails();
    }
}