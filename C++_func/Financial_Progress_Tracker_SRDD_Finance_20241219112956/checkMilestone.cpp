bool FinancialGoal::checkMilestone() {
    for (double milestone : milestones) {
        if (currentAmount >= milestone) {
            cout << "Milestone reached for " << name << ": " << milestone << endl;
            return true;
        }
    }
    return false;
}