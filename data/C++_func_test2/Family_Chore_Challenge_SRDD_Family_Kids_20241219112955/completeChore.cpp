void completeChore(Chore* chore, bool onTime) {
        if (chore->isChoreComplete(onTime)) {
            completedChores.push_back(chore);
            points += chore->points;
            cout << name << " completed the chore: " << chore->name << " and earned " << chore->points << " points!" << endl;
            triggerAchievements();
        } else {
            cout << "Chore '" << chore->name << "' was not completed on time!" << endl;
        }
    }