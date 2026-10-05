def process_controller_input(self, raw_input):
        commands = self.map_input_to_commands(raw_input, self.controller_mapping)
        return commands