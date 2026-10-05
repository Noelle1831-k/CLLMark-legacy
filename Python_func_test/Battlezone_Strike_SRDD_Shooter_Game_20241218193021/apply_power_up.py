def apply_power_up(self, power_up):
        '''
        Applies a power-up effect to the player's tank.
        '''
        power_up.apply(self.tank)
        self.power_ups.append(power_up)
        print(f"{self.username} used {power_up.name}!")