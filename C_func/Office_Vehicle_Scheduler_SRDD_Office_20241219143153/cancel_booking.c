void cancel_booking() {
    printf("Enter Booking ID to Cancel: ");
    int booking_id = get_int_input();
    Booking *booking = find_booking_by_id(booking_id);
    if (booking) {
        update_availability(booking->vehicle_id, 1);
        delete_booking(booking_id);
        printf("Booking cancelled successfully.\n");
    } else {
        printf("Booking not found.\n");
    }
}