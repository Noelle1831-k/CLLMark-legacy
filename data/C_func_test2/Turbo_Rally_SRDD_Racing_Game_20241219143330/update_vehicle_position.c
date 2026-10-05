void update_vehicle_position(Vehicle *v, float deltaTime) {
    v->speed = v->speed + v->acceleration * deltaTime;
    v->position = v->position + v->speed * deltaTime;
}