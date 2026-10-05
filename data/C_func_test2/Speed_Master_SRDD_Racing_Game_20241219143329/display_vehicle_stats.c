void display_vehicle_stats(const struct Vehicle *v) {
    printf("Vehicle: %s\n", v->name);
    printf("Max Speed: %.2f km/h\n", v->max_speed);
    printf("Acceleration: %.2f m/sÂ²\n", v->acceleration);
    printf("Handling: %.2f\n", v->handling);
}