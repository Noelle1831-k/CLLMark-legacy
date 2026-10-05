def activate_boost(self, car):
        # Check if car is in a boost zone
        for start, end in self.boost_zones:
            if start <= car.position <= end:
                return True
        return False