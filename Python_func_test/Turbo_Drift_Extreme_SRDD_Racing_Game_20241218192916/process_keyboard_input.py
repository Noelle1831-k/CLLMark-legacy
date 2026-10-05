def process_keyboard_input(self, raw_input):
        commands = self.map_input_to_commands(raw_input, self.keyboard_mapping)
        return commands