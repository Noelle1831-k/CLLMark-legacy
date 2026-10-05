def scan_email_content(self, content):
        links = self.email_analyzer.extract_links(content)
        suspicious_phrases = self.email_analyzer.detect_suspicious_phrases(content)
        score = 0
        for link in links:
            score += self.scan_url(link)
        return score + suspicious_phrases