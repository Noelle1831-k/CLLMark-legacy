def shoot(self):
        print("Shooting...", flush=True)
        if self.rifle.silence_shot():
            self.target_eliminated = True
            self.score += 100
            print("Target eliminated silently!", flush=True)
        else:
            print("Missed the target!", flush=True)