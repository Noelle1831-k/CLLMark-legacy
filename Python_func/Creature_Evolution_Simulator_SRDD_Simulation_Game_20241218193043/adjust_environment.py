def adjust_environment(self):
        try:
            temperature_change = float(input("Enter temperature change: "))
            food_change = float(input("Enter food availability change: "))
            predator_change = float(input("Enter predator density change: "))
            self.environment.change_conditions(temperature_change, food_change, predator_change)
        except ValueError:
            print("Invalid input. Please enter numeric values.")