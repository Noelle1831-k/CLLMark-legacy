def complete_service(self, vehicle_id, service_date):
        for service in self.services:
            if service.vehicle_id == vehicle_id and service.service_date == service_date:
                service.mark_complete()
                self.vehicle_manager.vehicles[vehicle_id].update_maintenance_status(False)
                print(f"Service for vehicle {vehicle_id} on {service_date} completed.")
                return
        print("Service record not found.")