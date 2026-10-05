void decreaseStamina(int cost) {
        stamina -= cost;
        if (stamina < 0) stamina = 0;
    }