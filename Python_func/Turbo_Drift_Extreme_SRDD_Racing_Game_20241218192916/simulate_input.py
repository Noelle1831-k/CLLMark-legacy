def simulate_input(self):
        simulated_keyboard_input = ['w', 'a', 'space']
        simulated_controller_input = ['up', 'left', 'button2']
        keyboard_commands = self.process_keyboard_input(simulated_keyboard_input)
        controller_commands = self.process_controller_input(simulated_controller_input)
        return keyboard_commands + controller_commands