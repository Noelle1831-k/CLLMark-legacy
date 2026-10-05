def choose_control_mode(self):
        choice = input("Choose control mode (manual/auto): ").strip().lower()
        if choice == "manual":
            self.manual_control = True
        elif choice == "auto":
            self.manual_control = False
        else:
            print("Invalid choice. Defaulting to auto mode.")
            self.manual_control = False