def add_vehicle(self, vehicle_id):
        if vehicle_id not in self.vehicles:
            self.vehicles[vehicle_id] = Vehicle(vehicle_id)
            print(f"Vehicle {vehicle_id} added.")
        else:
            print(f"Vehicle {vehicle_id} already exists.")