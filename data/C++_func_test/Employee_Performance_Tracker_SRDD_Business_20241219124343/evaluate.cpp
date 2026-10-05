void PerformanceEvaluation::evaluate(const Employee& employee, int score) {
    string evaluation;
    if (score > 80) {
        evaluation = "Excellent";
    } else if (score > 60) {
        evaluation = "Good";
    } else {
        evaluation = "Needs Improvement";
    }
    evaluations[employee.getEmployeeID()] = evaluation;
    cout << "Evaluation for " << employee.getName() << ": " << evaluation << endl;
}