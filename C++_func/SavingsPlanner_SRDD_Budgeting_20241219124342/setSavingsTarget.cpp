void SavingsTracker::setSavingsTarget() {
    cout << "Set your savings target: ";
    double target;
    cin >> target;
    saveSavingsTarget(target);
    currentTarget = target;
    cout << "Savings target of " << target << " set." << endl;
}