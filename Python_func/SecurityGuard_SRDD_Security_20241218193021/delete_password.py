def delete_password(self, site):
        print(f"Deleting password for {site}")
        if site in self.passwords:
            del self.passwords[site]