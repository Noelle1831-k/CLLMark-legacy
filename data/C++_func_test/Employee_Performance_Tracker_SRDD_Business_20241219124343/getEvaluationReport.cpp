void PerformanceEvaluation::getEvaluationReport(const Employee& employee) const {
    int id = employee.getEmployeeID();
    if (evaluations.end() != evaluations.find(id)) {
        cout << "Evaluation for " << employee.getName() << ": " << evaluations.at(id) << endl;
    } else {
        cout << "No evaluation found for " << employee.getName() << endl;
    }
}