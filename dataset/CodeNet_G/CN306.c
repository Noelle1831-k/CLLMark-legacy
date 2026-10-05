#define MOON_RADIUS 1800.0
#define MOON_ORBIT_RADIUS 380000.0
#define KAGUYA_ORBIT_RADIUS (MOON_RADIUS + 100.0)
#define MOON_ORBIT_PERIOD (2500000.0 / 60.0)  
#define KAGUYA_ORBIT_PERIOD (120.0)          
#define PI 3.141592653589793
double calculate_hidden_time(int m, int t) {
    double hidden_time = 0.0;
    double moon_angular_velocity = 2 * PI / MOON_ORBIT_PERIOD;
    double kaguya_angular_velocity = 2 * PI / KAGUYA_ORBIT_PERIOD;
    double moon_angle = m * PI / 180.0;
    double kaguya_angle = 0;
    for (int i = 0; i < t; i++) {
        double moon_x = MOON_ORBIT_RADIUS * cos(moon_angle);
        double moon_y = MOON_ORBIT_RADIUS * sin(moon_angle);
        double kaguya_x = KAGUYA_ORBIT_RADIUS * cos(kaguya_angle);
        double kaguya_z = KAGUYA_ORBIT_RADIUS * sin(kaguya_angle);
        double relative_x = kaguya_x - moon_x;
        double relative_y = -moon_y;
        double relative_z = kaguya_z;
        double dot_product = MOON_ORBIT_RADIUS * relative_x;
        double kaguya_moon_distance = sqrt(relative_x * relative_x + relative_y * relative_y + relative_z * relative_z);
        double cos_theta = dot_product / (MOON_ORBIT_RADIUS * kaguya_moon_distance);
        if (cos_theta < 0 && kaguya_moon_distance < MOON_RADIUS) {
            hidden_time += 1.0;
        }
        moon_angle += moon_angular_velocity;
        kaguya_angle += kaguya_angular_velocity;
    }
    return hidden_time;
}
