def scan_system(self):
        self.check_security_patches()
        self.verify_user_permissions()
        return self.vulnerabilities