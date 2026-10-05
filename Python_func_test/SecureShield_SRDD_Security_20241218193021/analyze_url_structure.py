def analyze_url_structure(self, url):
        if "login" in url or "secure" in url:
            return 5
        return 0