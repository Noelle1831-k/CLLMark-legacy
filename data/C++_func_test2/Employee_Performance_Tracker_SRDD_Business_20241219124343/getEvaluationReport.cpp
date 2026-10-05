void PerformanceEvaluation::getEvaluationReport(const Employee& employee) const {
    int id = employee.getEmployeeID();
    if (evaluations.find(id) != evaluations.end()) {
        cout << "Evaluation for " << employee.getName() << ": " << evaluations.at(id) << endl;
    } else {
        cout << "No evaluation found for " << employee.getName() << endl;
    }
}