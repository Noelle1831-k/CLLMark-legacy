def main():
    database = Database()
    database.load_phishing_database()
    phishing_detector = PhishingDetector(database)
    alert_system = AlertSystem()
    browser_extension = BrowserExtension(phishing_detector, alert_system)
    browser_extension.integrate_with_browser()
    browser_extension.monitor_browsing_activity()