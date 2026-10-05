def view_maintenance_schedule(self):
        if not self.services:
            print("No maintenance scheduled.")
        for service in self.services:
            status = "Completed" if service.is_complete else "Pending"
            print(f"Vehicle {service.vehicle_id} service on {service.service_date}: {status}")