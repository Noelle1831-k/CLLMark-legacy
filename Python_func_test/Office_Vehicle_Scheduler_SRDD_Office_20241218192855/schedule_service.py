def schedule_service(self, vehicle_id, service_date):
        if vehicle_id in self.vehicle_manager.vehicles:
            new_service = Service(vehicle_id, service_date)
            self.services.append(new_service)
            self.vehicle_manager.schedule_maintenance(vehicle_id)
            print(f"Service scheduled for vehicle {vehicle_id} on {service_date}.")
        else:
            print(f"Vehicle {vehicle_id} does not exist.")