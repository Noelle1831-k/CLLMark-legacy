void Vehicle::customizeVehicle(int newSpeed, int newAccel, int newHandle) {
    maxSpeed = newSpeed;
    acceleration = newAccel;
    handling = newHandle;
    cout << "Vehicle customized: " << type << endl;
}