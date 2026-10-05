def check_availability(self, vehicle_id):
        if vehicle_id in self.vehicles:
            return self.vehicles[vehicle_id].is_available()
        return False