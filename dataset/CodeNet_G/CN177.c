#define EARTH_RADIUS 6378.1
#define PI 3.14159265358979323846
double to_radians(double degree) {
    return degree * (PI / 180.0);
}
int calculate_distance(double lat1, double lon1, double lat2, double lon2) {
    lat1 = to_radians(lat1);
    lon1 = to_radians(lon1);
    lat2 = to_radians(lat2);
    lon2 = to_radians(lon2);
    double delta_lon = lon2 - lon1;
    double delta_sigma = acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(delta_lon));
    double distance = EARTH_RADIUS * delta_sigma;
    return (int)round(distance);
}