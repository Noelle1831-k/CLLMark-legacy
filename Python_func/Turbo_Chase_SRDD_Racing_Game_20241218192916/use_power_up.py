def use_power_up(self):
        if self.power_ups:
            power_up = self.power_ups.pop()
            power_up.activate()
        else:
            print("No power-ups available to use.")