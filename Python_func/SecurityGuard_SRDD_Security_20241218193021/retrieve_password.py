def retrieve_password(self, site):
        print(f"Retrieving password for {site}")
        return self.passwords.get(site, None)