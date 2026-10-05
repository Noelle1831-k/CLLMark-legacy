def revoke_access(self, user):
        print(f"Revoking access from {user}...")
        time.sleep(1)  # Simulate access revocation process
        if user in self.access_list:
            del self.access_list[user]
            print(f"Access revoked from {user}.")
        else:
            print(f"No access found for {user}.")