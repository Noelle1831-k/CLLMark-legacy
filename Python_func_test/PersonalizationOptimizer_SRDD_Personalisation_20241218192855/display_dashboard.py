def display_dashboard(self, settings):
        # Display the dashboard with current settings
        print("Displaying Dashboard:", flush=True)
        for key, value in settings.items():
            print(f"{key}: {value}", flush=True)