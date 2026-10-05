def send_email(self, goal_name, milestone_name):
        subject = f"Milestone Reached: {milestone_name}"
        body = f"Congratulations! You have reached the milestone '{milestone_name}' for your goal '{goal_name}'. Keep up the good work!"
        msg = MIMEMultipart()
        msg['From'] = self.email_user
        msg['To'] = self.email_user
        msg['Subject'] = subject
        msg.attach(MIMEText(body, 'plain'))
        try:
            server = smtplib.SMTP(self.email_server, self.email_port)
            server.starttls()
            server.login(self.email_user, self.email_password)
            text = msg.as_string()
            server.sendmail(self.email_user, self.email_user, text)
            server.quit()
            print(f"Email sent successfully for milestone '{milestone_name}' of goal '{goal_name}'")
        except Exception as e:
            print(f"Failed to send email: {e}")