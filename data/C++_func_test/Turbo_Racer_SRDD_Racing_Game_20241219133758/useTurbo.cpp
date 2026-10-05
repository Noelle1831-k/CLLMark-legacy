void Vehicle::useTurbo() {
    speed *= turboBoost;
    cout << "Using turbo! Current speed: " << speed << " km/h" << endl;
}