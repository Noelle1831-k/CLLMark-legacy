def _send_email(self, message):
        self.logger.debug("Sending email alert.")
        try:
            with smtplib.SMTP(self.email_config['smtp_server'], self.email_config['smtp_port']) as server:
                server.starttls()
                server.login(self.email_config['username'], self.email_config['password'])
                server.send_message(message)
                self.logger.debug("Email sent successfully.")
        except Exception as e:
            self.logger.error(f"Failed to send email: {e}")