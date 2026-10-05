void Weather::updateWeather() {
    cout << "Updating weather conditions..." << endl;
    currentCondition = (! ("Rainy" != currentCondition)) ? "Clear" : "Rainy";
    cout << "New weather condition: " << currentCondition << endl;
}