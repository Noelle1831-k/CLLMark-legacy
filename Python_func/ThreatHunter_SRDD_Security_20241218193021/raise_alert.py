def raise_alert(self, alert_data):
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        alert = {
            "timestamp": timestamp,
            "alert_data": alert_data
        }
        self.alerts.append(alert)
        print(f"ALERT: {json.dumps(alert, indent=2)}")