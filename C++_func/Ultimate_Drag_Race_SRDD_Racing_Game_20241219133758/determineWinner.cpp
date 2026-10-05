string Race::determineWinner() {
    double time1 = physics.calculateTime(car1, track);
    double time2 = physics.calculateTime(car2, track);
    if (time1 < time2)
        return "Player 1";
    else if (time2 < time1)
        return "Player 2";
    else
        return "It's a tie";
}