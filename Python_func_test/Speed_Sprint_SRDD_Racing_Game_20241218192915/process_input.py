def process_input(self):
        command = input("Enter command (accelerate/shift/customize): ")
        if command == "accelerate":
            self.player.vehicle.accelerate()
        elif command == "shift":
            self.player.shift_gear()
        elif command == "customize":
            option = input("Enter customization option (nitro_boost/weight_reduction): ")
            value = int(input(f"Enter value for {option}: "))
            self.player.vehicle.customize(option, value)
            self.player.vehicle.apply_customization()
        else:
            print("Invalid command")