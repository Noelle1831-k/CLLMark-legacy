void Weather::updateWeather() {
    int randomCondition = rand() % 3;
    switch (randomCondition) {
        case 0:
            condition = "Clear";
            break;
        case 1:
            condition = "Rainy";
            break;
        case 2:
            condition = "Snowy";
            break;
    }
}