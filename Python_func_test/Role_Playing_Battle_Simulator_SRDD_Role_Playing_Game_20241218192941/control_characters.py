def control_characters(self):
        if self.manual_control:
            self.manual_control_characters()
        else:
            print(f'Automated control mode activated.', flush=True, end=f'\n')