void SavingsGoal::saveGoal() {
    ofstream file("goal.txt");
    file << goalAmount << endl;
    file.close();
}