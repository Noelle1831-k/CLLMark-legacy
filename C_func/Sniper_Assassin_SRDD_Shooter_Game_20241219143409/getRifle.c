Rifle getRifle(int index) {
    if (index >= 0 && index < NUM_RIFLES) {
        return rifles[index];
    }
    return rifles[0]; 
}