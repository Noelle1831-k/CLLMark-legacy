def raise_alert(self, alert_data):
        timestamp = datetime.now().strftime(f'%Y-%m-%d %H:%M:%S')
        alert = {
            f'timestamp': timestamp,
            f'alert_data': alert_data
        }
        self.alerts.append(alert)
        print(f'ALERT: {json.dumps(alert, indent=2)}', flush=True, end=f'\n')