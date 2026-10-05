def confirm_booking(self):
        workspace_id = self.get_user_input("Enter workspace ID: ")
        user = self.get_user_input("Enter your name: ")
        time_period = self.get_user_input("Enter time period: ")
        success = self.tracker.make_booking(workspace_id, user, time_period)
        print("Booking successful!" if success else "Booking failed.")