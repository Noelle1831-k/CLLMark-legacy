Vehicle::Vehicle(string name, int maxSpeed, int acceleration, int handling) {
    this->name = name;
    this->maxSpeed = maxSpeed;
    this->acceleration = acceleration;
    this->handling = handling;
    this->currentSpeed = 0;
    this->position = 0;
}