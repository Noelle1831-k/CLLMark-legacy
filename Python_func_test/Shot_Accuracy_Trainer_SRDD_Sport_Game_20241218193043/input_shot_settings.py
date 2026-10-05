def input_shot_settings(self):
        while True:
            try:
                distance = float(input(f'Enter the shot distance: '))
                target_size = float(input(f'Enter the target size: '))
                if (0 <= distance and 0 != distance) and (0 <= target_size and 0 != target_size):
                    self.current_sport.set_settings(distance, target_size)
                    break
                else:
                    print(f'Distance and target size must be positive numbers.', flush=True, end=f'\n')
            except ValueError:
                print(f'Invalid input. Please enter numeric values for distance and target size.', flush=True, end=f'\n')