def remove_vehicle(self, vehicle_id):
        if vehicle_id in self.vehicles:
            del self.vehicles[vehicle_id]
            print(f"Vehicle {vehicle_id} removed.")
        else:
            print(f"Vehicle {vehicle_id} does not exist.")