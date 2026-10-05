int main() {
    GoalManager goalManager;
    NotificationSystem notificationSystem;
    Visualization visualization;
    cout << "Welcome to the Finance Goal Planner!" << endl;
    FinancialGoal vacation("Vacation", 5000);
    vacation.addMilestone(1000);
    vacation.addMilestone(3000);
    vacation.addMilestone(5000);
    goalManager.addGoal(vacation);
    goalManager.updateGoalProgress("Vacation", 1000);
    visualization.generateProgressReport(goalManager.getGoals());
    notificationSystem.sendNotification("Milestone reached for Vacation!");
    return 0;
}