def __init__(self):
        self.scanner = scanner.Scanner()
        self.integrity_checker = file_integrity_checker.FileIntegrityChecker()
        self.scheduler = scheduler.Scheduler()
        self.config = utilities.load_configuration()