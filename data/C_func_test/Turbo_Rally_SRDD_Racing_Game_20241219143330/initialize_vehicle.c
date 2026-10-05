void initialize_vehicle(Vehicle *v, const char *name, float speed, float acceleration, float handling, float durability) {
    strcpy(v->name, name);
    v->speed = speed;
    v->position = 0.0f;
    v->acceleration = acceleration;
    v->handling = handling;
    v->durability = durability;
}