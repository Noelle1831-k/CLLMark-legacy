def hit(self):
        print(f'Target at {self.position} hit!')
        self.position = self.spawn()
        self.is_hit = True