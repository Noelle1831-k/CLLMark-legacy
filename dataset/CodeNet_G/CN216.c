int calculate_savings(int w) {
    int base_fee = 1150;
    int last_month_fee = 4280;
    int total_fee;
    if (w <= 10) {
        total_fee = base_fee;
    } else if (w <= 20) {
        total_fee = base_fee + (w - 10) * 125;
    } else if (w <= 30) {
        total_fee = base_fee + 10 * 125 + (w - 20) * 140;
    } else {
        total_fee = base_fee + 10 * 125 + 10 * 140 + (w - 30) * 160;
    }
    return last_month_fee - total_fee;
}