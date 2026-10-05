def __init__(self, email_config):
        self.email_config = email_config
        self.logger = logging.getLogger('AlertSystem')
        self.logger.setLevel(logging.DEBUG)
        handler = logging.FileHandler('alert_system.log')
        handler.setLevel(logging.DEBUG)
        formatter = logging.Formatter('%(asctime)s - %(levelname)s - %(message)s')
        handler.setFormatter(formatter)
        self.logger.addHandler(handler)