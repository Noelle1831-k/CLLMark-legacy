def scan_url(self, url):
        reputation_score = self.url_scanner.check_url_reputation(url)
        structure_score = self.url_scanner.analyze_url_structure(url)
        return reputation_score + structure_score