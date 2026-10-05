void PerformanceReport::saveToFile(const Employee& employee, const string& filename) {
    ofstream file(filename.c_str());
    if (file.is_open()) {
        file << "Performance Report for " << employee.getName() << endl;
        file << "Department: " << employee.getDepartment() << endl;
        file << "Employee ID: " << employee.getEmployeeID() << endl;
        file.close();
        cout << "Report saved to " << filename << endl;
    } else {
        cout << "Failed to save the report!" << endl;
    }
}