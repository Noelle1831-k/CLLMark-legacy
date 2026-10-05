def select_scale_type(self):
        '''
        Allows the user to select a scale type.
        '''
        scale_type_input = input(f'Enter the scale type (e.g., major, minor, pentatonic): ')
        if scale_type_input in self.scale_generator.scales:
            return scale_type_input
        else:
            print(f'Invalid scale type. Defaulting to major.', flush=True, end=f'\n')
            return f'major'  # Default to major if invalid input