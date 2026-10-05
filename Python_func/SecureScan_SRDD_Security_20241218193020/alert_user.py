def alert_user(self, message):
        # Send a real-time desktop notification to the user
        notification.notify(
            title="SecureScan Alert",
            message=message,
            app_name="SecureScan",
            timeout=10  # Notification duration in seconds
        )