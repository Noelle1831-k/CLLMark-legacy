def update_environment(self):
        # Update environmental effects
        self.effects.append("effect")
        if len(self.effects) > 10:
            self.effects.pop(0)