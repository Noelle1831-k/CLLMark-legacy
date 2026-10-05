int main() {
    Vehicle car1(0.5, 200);
    Vehicle car2(0.7, 220);
    Track track(1000, "asphalt");
    Race race(&car1, &car2, &track);
    race.startRace();
    race.checkWinner();
    return 0;
}