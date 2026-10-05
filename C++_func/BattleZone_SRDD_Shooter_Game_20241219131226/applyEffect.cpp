void applyEffect(Tank &tank) {
        if (type == "Health Boost") {
            cout << "Applying " << type << " power-up to " << tank.getPosition().first << endl;
            tank.takeDamage(-20); 
        }
    }