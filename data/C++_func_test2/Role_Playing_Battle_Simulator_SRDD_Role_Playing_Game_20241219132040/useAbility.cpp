void useAbility(Character& target) override {
        cout << "Casting Fireball on " << target.getName() << "!" << endl;
        target.takeDamage(30);
    }