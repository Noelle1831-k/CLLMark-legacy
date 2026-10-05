def _compose_alert_message(self, threat):
        self.logger.debug("Composing alert message.")
        message = MIMEMultipart()
        message['From'] = self.email_config['from']
        message['To'] = self.email_config['to']
        message['Subject'] = f"Security Alert: {threat['type']} Detected"
        body = f"Alert! Detected {threat['type']} with {threat['severity']} severity.\nPlease take immediate action."
        message.attach(MIMEText(body, 'plain'))
        self.logger.debug("Alert message composed.")
        return message