void SavingsGoal::loadGoal() {
    ifstream file("goal.txt");
    if (file.is_open()) {
        file >> goalAmount;
        file.close();
    }
}