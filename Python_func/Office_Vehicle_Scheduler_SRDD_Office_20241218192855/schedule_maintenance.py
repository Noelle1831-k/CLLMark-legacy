def schedule_maintenance(self, vehicle_id):
        if vehicle_id in self.vehicles:
            self.vehicles[vehicle_id].update_maintenance_status(True)
            print(f"Vehicle {vehicle_id} scheduled for maintenance.")