def apply_nitro(self):
        if self.nitro_level > 0:
            print(f"{self.name} activated Nitro Boost!")
            self.current_speed += self.max_speed * 0.3
            self.nitro_level -= random.randint(10, 20)
        else:
            print("Nitro Depleted!")
        self.nitro_level = max(0, self.nitro_level)
        print(f"Nitro Level: {self.nitro_level}")