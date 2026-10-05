void Race::startRace() {
    graphics.renderRaceStart();
    printf("The race has begun!\n");
    this_thread::sleep_for(chrono::seconds(2));
    double time1 = physics.calculateTime(car1, track);
    double time2 = physics.calculateTime(car2, track);
    printf("Player 1 finished in %f seconds.\n", time1);
    printf("Player 2 finished in %f seconds.\n", time2);
    string winner = determineWinner();
    printf("The winner is: %s!\n", winner.c_str());
    graphics.renderRaceEnd();
}