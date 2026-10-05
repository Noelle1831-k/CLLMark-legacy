void Weather::updateWeather() {
    cout << "Updating weather conditions..." << endl;
    currentCondition = (currentCondition == "Rainy") ? "Clear" : "Rainy";
    cout << "New weather condition: " << currentCondition << endl;
}