def send_alert(self, frame):
        msg = MIMEMultipart()
        msg['From'] = self.username
        msg['To'] = self.recipient
        msg['Subject'] = "Security Alert"
        body = "Suspicious activity detected."
        msg.attach(MIMEText(body, 'plain'))
        text = msg.as_string()
        try:
            server = smtplib.SMTP(self.smtp_server, self.smtp_port)
            server.starttls()
            server.login(self.username, self.password)
            server.sendmail(self.username, self.recipient, text)
        except Exception as e:
            print(f"Failed to send alert: {e}")
        finally:
            server.quit()