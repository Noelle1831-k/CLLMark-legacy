int Party::calculateTotalPower() {
    int totalPower = 0;
    for (size_t i = 0; i < members.size(); i++) {
        totalPower += members[i].calculatePower();
    }
    return totalPower;
}