void Environment::adjustHumidity(int delta) {
    humidity = humidity + delta;
    cout << "Humidity adjusted to: " << humidity << endl;
}