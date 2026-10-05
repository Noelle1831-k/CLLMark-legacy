def shoot(self):
        print("Shooting...")
        if self.rifle.silence_shot():
            self.target_eliminated = True
            self.score += 100
            print("Target eliminated silently!")
        else:
            print("Missed the target!")