void display_vehicle_status(const Vehicle *v) {
    printf("Vehicle: %s | Speed: %.2f | Position: %.2f | Durability: %.2f\n", v->name, v->speed, v->position, v->durability);
}