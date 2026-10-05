void Race::startRace() {
    graphics.renderRaceStart();
    cout << "The race has begun!\n";
    this_thread::sleep_for(chrono::seconds(2));
    double time1 = physics.calculateTime(car1, track);
    double time2 = physics.calculateTime(car2, track);
    cout << "Player 1 finished in " << time1 << " seconds.\n";
    cout << "Player 2 finished in " << time2 << " seconds.\n";
    string winner = determineWinner();
    cout << "The winner is: " << winner << "!\n";
    graphics.renderRaceEnd();
}