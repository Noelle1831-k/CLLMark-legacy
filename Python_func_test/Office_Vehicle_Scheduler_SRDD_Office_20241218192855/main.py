def main():
    vehicle_manager = VehicleManager()
    booking_manager = BookingManager(vehicle_manager)
    maintenance_manager = MaintenanceManager(vehicle_manager)
    # Example operations with datetime conversion
    vehicle_manager.add_vehicle("V001")
    vehicle_manager.add_vehicle("V002")
    booking_manager.book_vehicle("V001", datetime(2023, 10, 1, 9, 0), datetime(2023, 10, 1, 17, 0))
    maintenance_manager.schedule_service("V002", datetime(2023, 10, 5))
    # View current bookings and maintenance schedule
    booking_manager.view_bookings()
    maintenance_manager.view_maintenance_schedule()