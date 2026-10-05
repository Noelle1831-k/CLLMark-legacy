def send_alert(self, threats):
        self.logger.info(f'Preparing to send alerts for detected threats.')
        for threat in threats:
            self.logger.debug(f'Processing threat: {threat}')
            alert_message = self._compose_alert_message(threat)
            self._send_email(alert_message)
            self.logger.info(f'Alert sent for threat: {threat[f"type"]} with {threat[f"severity"]} severity.')