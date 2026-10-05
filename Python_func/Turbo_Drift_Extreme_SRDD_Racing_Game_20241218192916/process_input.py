def process_input(self):
        commands = self.input_handler.simulate_input()
        self.car.handle_input(commands)