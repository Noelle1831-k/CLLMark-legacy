void PerformanceReport::generateReport(const Employee& employee) {
    cout << "Generating report for " << employee.getName() << "..." << endl;
    employee.getDetails();
}