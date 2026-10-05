void SavingsTracker::saveSavingsTarget(double target) {
    ofstream outfile("savings_target.txt");
    if (outfile.is_open()) {
        outfile << target << endl;
        outfile.close();
    }
}