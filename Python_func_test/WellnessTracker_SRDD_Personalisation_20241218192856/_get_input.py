def _get_input(self, prompt):
        while True:
            try:
                value = float(input(prompt))
                if 0 <= value <= 10:
                    return value
                else:
                    print('Please enter a value between 0 and 10.')
            except ValueError:
                print('Invalid input. Please enter a numeric value.')