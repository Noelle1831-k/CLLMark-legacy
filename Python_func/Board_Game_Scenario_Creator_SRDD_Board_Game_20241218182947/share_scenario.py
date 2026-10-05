def share_scenario(self, filename, email):
        '''
        Share the scenario file via email.
        Parameters:
        filename (str): The name of the file to be shared.
        email (str): The recipient's email address.
        '''
        with open(filename, 'r') as file:
            scenario_data = file.read()
        msg = MIMEMultipart()
        msg['From'] = 'noreply@boardgamecreator.com'
        msg['To'] = email
        msg['Subject'] = 'Shared Board Game Scenario'
        body = f"Please find the attached scenario file: {filename}"
        msg.attach(MIMEText(body, 'plain'))
        attachment = MIMEText(scenario_data)
        attachment.add_header('Content-Disposition', 'attachment', filename=filename)
        msg.attach(attachment)
        try:
            server = smtplib.SMTP('smtp.example.com', 587)
            server.starttls()
            server.login('noreply@boardgamecreator.com', 'password')
            text = msg.as_string()
            server.sendmail('noreply@boardgamecreator.com', email, text)
            server.quit()
            print(f"Email sent successfully to {email}")
        except Exception as e:
            print(f"Failed to send email: {e}")