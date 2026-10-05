void grantReward(Child& child) {
        if (child.points >= pointsRequired) {
            cout << child.name << " has earned the reward: " << rewardName << endl;
        } else {
            cout << child.name << " needs more points to earn this reward." << endl;
        }
    }