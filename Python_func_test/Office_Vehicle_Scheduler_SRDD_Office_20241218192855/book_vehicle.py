def book_vehicle(self, vehicle_id, start_time, end_time):
        if self.vehicle_manager.check_availability(vehicle_id):
            new_booking = Booking(vehicle_id, start_time, end_time)
            if not any(b.is_conflict(new_booking) for b in self.bookings):
                self.bookings.append(new_booking)
                self.vehicle_manager.vehicles[vehicle_id].update_availability(False)
                print(f"Vehicle {vehicle_id} booked from {start_time} to {end_time}.")
            else:
                print("Booking conflict detected.")
        else:
            print(f"Vehicle {vehicle_id} is not available.")