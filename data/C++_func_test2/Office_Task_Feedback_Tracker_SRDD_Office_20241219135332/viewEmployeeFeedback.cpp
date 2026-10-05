void Manager::viewEmployeeFeedback(int employeeId) {
    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i].getId() == employeeId) {
            employees[i].viewFeedback();
        }
    }
}