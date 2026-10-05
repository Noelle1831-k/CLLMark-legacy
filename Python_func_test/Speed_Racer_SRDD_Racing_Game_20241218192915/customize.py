def customize(self, new_specs):
        self.speed = new_specs.get('speed', self.speed)
        self.handling = new_specs.get('handling', self.handling)
        self.acceleration = new_specs.get('acceleration', self.acceleration)
        self.color = new_specs.get('color', self.color)