def check_system_health(self):
        self.health_status['cpu'] = psutil.cpu_percent(interval=1)
        self.health_status['memory'] = psutil.virtual_memory().percent
        self.health_status['disk'] = psutil.disk_usage('/').percent
        print(f"System Health: {self.health_status}")