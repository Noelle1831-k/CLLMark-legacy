void Artist::perform() {
    if (available) {
        cout << name << " is performing!" << endl;
    } else {
        cout << name << " is not available to perform." << endl;
    }
}