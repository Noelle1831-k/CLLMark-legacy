def __init__(self):
        '''
        Initialize the PrivacyShield application by creating instances of all core components.
        '''
        self.encryptor = Encryptor()
        self.cleaner = Cleaner()
        self.browser_extension = BrowserExtension()
        self.password_manager = PasswordManager()
        self.key = generate_key(32)  # Generate a 256-bit encryption key