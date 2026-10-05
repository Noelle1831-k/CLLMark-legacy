def cancel_booking(self, vehicle_id, start_time, end_time):
        for booking in self.bookings:
            if booking.vehicle_id == vehicle_id and booking.start_time == start_time and booking.end_time == end_time:
                self.bookings.remove(booking)
                self.vehicle_manager.vehicles[vehicle_id].update_availability(True)
                print(f"Booking for vehicle {vehicle_id} from {start_time} to {end_time} canceled.")
                return
        print("Booking not found.")