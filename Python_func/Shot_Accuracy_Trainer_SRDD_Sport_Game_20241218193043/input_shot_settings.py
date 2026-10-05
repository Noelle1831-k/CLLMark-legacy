def input_shot_settings(self):
        while True:
            try:
                distance = float(input("Enter the shot distance: "))
                target_size = float(input("Enter the target size: "))
                if distance > 0 and target_size > 0:
                    self.current_sport.set_settings(distance, target_size)
                    break
                else:
                    print("Distance and target size must be positive numbers.")
            except ValueError:
                print("Invalid input. Please enter numeric values for distance and target size.")