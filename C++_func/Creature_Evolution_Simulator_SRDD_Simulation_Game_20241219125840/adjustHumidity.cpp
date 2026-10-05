void Environment::adjustHumidity(int delta) {
    humidity += delta;
    cout << "Humidity adjusted to: " << humidity << endl;
}