void Vehicle::activateNitro() {
    nitro->activate();
    speed += 50;
    cout << "Nitro activated! Speed increased to " << speed << "." << endl;
}