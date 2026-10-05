void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
        cout << name << " took " << damage << " damage. Health: " << health << endl;
    }