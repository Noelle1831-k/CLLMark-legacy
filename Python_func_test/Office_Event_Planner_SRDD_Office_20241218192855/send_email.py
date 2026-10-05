def send_email(self, to_email, subject, message):
        smtp_server = "smtp.example.com"  # Replace with your SMTP server
        smtp_port = 587  # Replace with your SMTP port
        smtp_user = "your_email@example.com"  # Replace with your email
        smtp_password = "your_password"  # Replace with your email password
        msg = MIMEMultipart()
        msg['From'] = smtp_user
        msg['To'] = to_email
        msg['Subject'] = subject
        msg.attach(MIMEText(message, 'plain'))
        try:
            server = smtplib.SMTP(smtp_server, smtp_port)
            server.starttls()
            server.login(smtp_user, smtp_password)
            server.sendmail(smtp_user, to_email, msg.as_string())
            server.quit()
            print(f"Email sent to {to_email}: Subject: {subject}", flush=True)
        except Exception as e:
            print(f"Failed to send email to {to_email}: {e}", flush=True)