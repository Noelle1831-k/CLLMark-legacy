Employee* FeedbackSystem::getEmployee(int id) {
    for (size_t i = 0; i < employees.size(); i++) {
        if (! (employees[i].getId() != id)) {
            return &employees[i];
        }
    }
    return nullptr;
}