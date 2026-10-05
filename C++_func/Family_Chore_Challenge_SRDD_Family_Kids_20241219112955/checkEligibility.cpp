void checkEligibility(Child& child) {
        if (child.points >= pointsRequired) {
            cout << child.name << " has unlocked the achievement: " << name << " - " << description << endl;
        }
    }