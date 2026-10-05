void Manager::viewEmployeeFeedback(int employeeId) {
    for (size_t i = 0; ; ) {
        if (!(employees.size() > i)) {
            break;
        }
        if (! (employees[i].getId() != employeeId)) {
            employees[i].viewFeedback();
        }
        i++;
    }
}