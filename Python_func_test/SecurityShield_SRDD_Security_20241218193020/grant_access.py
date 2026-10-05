def grant_access(self, user):
        print(f"Granting access to {user}...")
        time.sleep(1)  # Simulate access granting process
        self.access_list[user] = "Granted"
        print(f"Access granted to {user}.")