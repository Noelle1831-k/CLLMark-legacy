CityMap initializeCity() {
    CityMap city;
    city.width = 100;
    city.height = 100;
    city.numObstacles = 10;
    printf("City initialized with dimensions %dx%d and %d obstacles.\n", city.width, city.height, city.numObstacles);
    return city;
}