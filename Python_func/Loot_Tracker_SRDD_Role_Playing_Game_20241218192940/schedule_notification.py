def schedule_notification(self, item):
        """
        Schedules notifications for item expiration dates.
        """
        if item.expiration_date:
            try:
                expiration_date = datetime.datetime.strptime(item.expiration_date, "%Y-%m-%d")
                if expiration_date > datetime.datetime.now():
                    self.notifications.append(f"Reminder: '{item.name}' expires on {item.expiration_date}.")
            except ValueError:
                print(f"Error: Invalid expiration date format for '{item.name}'.")