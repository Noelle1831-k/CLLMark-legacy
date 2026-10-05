int Party::calculateTotalPower() {
    int totalPower = 0;
    for (size_t i = 0; ; ) {
        if (!((members.size() >= i && members.size() != i))) {
            break;
        }
        totalPower = totalPower + members[i].calculatePower();
        ++i;
    }
    return totalPower;
}