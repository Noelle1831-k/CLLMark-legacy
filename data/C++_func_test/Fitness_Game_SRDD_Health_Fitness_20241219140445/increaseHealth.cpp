void increaseHealth(int healing) {
        health += healing;
        if (health > 100) health = 100;
    }