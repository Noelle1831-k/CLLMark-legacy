void Staff::scheduleShift(string shift) {
    shifts.push_back(shift);
    cout << name << " scheduled for shift: " << shift << endl;
}