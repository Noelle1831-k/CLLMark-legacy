void decreaseHealth(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
            cout << name << " has no health left!" << endl;
        }
    }