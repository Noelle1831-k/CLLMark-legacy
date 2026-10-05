def confirm_action(self, action):
        confirmation = input(f"Are you sure you want to {action}? (yes/no): ").strip().lower()
        return confirmation == 'yes'