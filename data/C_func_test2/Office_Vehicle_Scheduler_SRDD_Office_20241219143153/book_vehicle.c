void book_vehicle() {
    printf("Enter Vehicle ID to Book: ");
    int vehicle_id = get_int_input();
    if (!is_vehicle_available(vehicle_id)) {
        printf("Vehicle is not available for booking.\n");
        return;
    }
    Booking new_booking;
    new_booking.booking_id = generate_booking_id();
    new_booking.vehicle_id = vehicle_id;
    printf("Enter Your Name: ");
    get_string_input(new_booking.user, 100);
    printf("Enter Booking Start Time (YYYY-MM-DD HH:MM): ");
    get_string_input(new_booking.start_time, 20);
    printf("Enter Booking End Time (YYYY-MM-DD HH:MM): ");
    get_string_input(new_booking.end_time, 20);
    save_booking(&new_booking);
    update_availability(vehicle_id, 0);
    printf("Vehicle booked successfully!\n");
}