bool FinancialGoal::checkMilestones() {
    bool milestoneReached = false;
    vector<double>::iterator it;
    for (it = milestones.begin(); it != milestones.end(); ) {
        if (currentAmount >= *it) {
            cout << "Milestone reached: " << *it << " for " << name << endl;
            it = milestones.erase(it); 
            milestoneReached = true;
        } else {
            ++it;
        }
    }
    return milestoneReached;
}