def control_opponents(self, vehicles):
        for vehicle in vehicles:
            if vehicle.current_speed < vehicle.max_speed / 2:
                vehicle.accelerate()
            else:
                vehicle.decelerate()