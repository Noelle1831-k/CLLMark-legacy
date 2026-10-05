def use_nitro(self):
        if self.nitro_available:
            self.speed += self.nitro
            self.nitro_available = False