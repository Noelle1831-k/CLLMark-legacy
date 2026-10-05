void createChore(string name, int points, string deadline) {
        Chore* chore = new Chore(name, points, deadline);
        chores.push_back(chore);
        cout << "Chore '" << name << "' created with " << points << " points and deadline: " << deadline << endl;
    }