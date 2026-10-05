def store_password(self, site, password):
        print(f"Storing password for {site}")
        self.passwords[site] = password