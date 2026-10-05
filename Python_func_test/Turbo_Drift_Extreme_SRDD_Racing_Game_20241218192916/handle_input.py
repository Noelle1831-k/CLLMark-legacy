def handle_input(self, commands):
        if 'accelerate' in commands:
            self.speed += 5
        if 'brake' in commands:
            self.speed -= 5
        if 'left' in commands:
            self.handling -= 1
        if 'right' in commands:
            self.handling += 1