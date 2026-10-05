def get_input(self):
        num_commands = random.randint(1, len(self.command_list))
        return random.sample(self.command_list, num_commands)