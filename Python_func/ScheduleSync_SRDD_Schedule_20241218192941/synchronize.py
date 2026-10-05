def synchronize(self, user):
        print(f"Synchronizing schedule for {user.name} across devices...")
        self.synced_devices.append(user.name)