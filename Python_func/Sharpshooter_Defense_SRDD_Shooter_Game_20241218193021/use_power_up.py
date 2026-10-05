def use_power_up(self, power_up):
        power_up.apply_effect(self)
        print("Player used power-up")