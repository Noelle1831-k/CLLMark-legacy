void create_vehicle(struct Vehicle *v, char *name, float max_speed, float acceleration, float handling) {
    snprintf(v->name, sizeof(v->name), "%s", name);
    v->max_speed = max_speed;
    v->acceleration = acceleration;
    v->handling = handling;
}