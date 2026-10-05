void Creature::adapt(Environment &env) {
    health += adaptability / 10;
    health += (env.adjustTemperature(0) - 25) / 5;
    health += (env.adjustHumidity(0) - 50) / 10;
    health += env.adjustFoodAvailability(0) / 10;
    health -= env.adjustPredatorPresence(0) / 5;
    cout << "Creature adapted. Health: " << health << endl;
}