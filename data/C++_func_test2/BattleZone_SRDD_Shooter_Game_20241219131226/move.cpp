void move() {
        cout << name << " is moving..." << endl;
        int dx = generateRandomNumber(-2, 2);
        int dy = generateRandomNumber(-2, 2);
        x += dx;
        y += dy;
        if (x < 0) x = 0;
        if (y < 0) y = 0;
    }