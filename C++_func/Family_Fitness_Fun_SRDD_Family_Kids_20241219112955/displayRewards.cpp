void User::displayRewards() {
    if (totalActivityPoints >= 50) {
        cout << "Congratulations " << name << "! You earned a Gold Reward!" << endl;
    } else if (totalActivityPoints >= 30) {
        cout << "Great job " << name << "! You earned a Silver Reward!" << endl;
    } else {
        cout << "Keep going " << name << "! You earned a Bronze Reward!" << endl;
    }
}