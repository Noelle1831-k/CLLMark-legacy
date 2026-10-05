void increaseStamina(int recovery) {
        stamina += recovery;
        if (stamina > 100) stamina = 100;
    }