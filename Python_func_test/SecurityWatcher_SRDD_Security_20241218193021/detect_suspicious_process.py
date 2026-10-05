def detect_suspicious_process(self, proc):
        try:
            return 'malicious' in proc.info['name'].lower()
        except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
            return False