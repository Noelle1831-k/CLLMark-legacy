void SavingsTracker::loadSavingsTarget() {
    ifstream infile("savings_target.txt");
    if (infile.is_open()) {
        infile >> currentTarget;
        cout << "Loaded savings target: " << currentTarget << endl;
        infile.close();
    }
}