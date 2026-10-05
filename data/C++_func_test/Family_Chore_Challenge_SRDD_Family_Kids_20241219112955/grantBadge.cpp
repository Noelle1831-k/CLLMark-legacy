void grantBadge(Child& child) {
        if (child.points >= pointsRequired) {
            child.badges.push_back(this);
            cout << child.name << " earned the '" << badgeName << "' badge!" << endl;
        }
    }