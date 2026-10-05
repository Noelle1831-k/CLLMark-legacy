def list_access(self):
        print("Current access list:")
        for user, status in self.access_list.items():
            print(f"{user}: {status}")