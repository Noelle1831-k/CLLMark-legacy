def send_email(self, digest):
        msg = MIMEText(digest)
        msg['Subject'] = 'Your Daily News Digest'
        msg['From'] = 'noreply@dailydigest.com'
        msg['To'] = 'user@example.com'
        try:
            with smtplib.SMTP('localhost') as server:
                server.send_message(msg)
            utils.log_activity("Email sent successfully.")
        except Exception as e:
            utils.log_activity(f"Failed to send email: {str(e)}")