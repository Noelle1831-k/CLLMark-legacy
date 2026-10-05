def map_input_to_commands(self, raw_input, mapping):
        commands = [mapping.get(key, '') for key in raw_input if key in mapping]
        return [command for command in commands if command]