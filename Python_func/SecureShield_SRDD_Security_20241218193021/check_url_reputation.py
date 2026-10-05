def check_url_reputation(self, url):
        if url in self.database.known_phishing_sites:
            return 10
        return 0