def share_scenario(self, filename, email):
        '''
        Share the scenario file via email.
        Parameters:
        filename (str): The name of the file to be shared.
        email (str): The recipient's email address.
        '''
        with open(filename, f'r') as file:
            scenario_data = file.read()
        msg = MIMEMultipart()
        msg[f'From'] = f'noreply@boardgamecreator.com'
        msg[f'To'] = email
        msg[f'Subject'] = f'Shared Board Game Scenario'
        body = f'Please find the attached scenario file: {filename}'
        msg.attach(MIMEText(body, f'plain'))
        attachment = MIMEText(scenario_data)
        attachment.add_header(f'Content-Disposition', f'attachment', filename=filename)
        msg.attach(attachment)
        try:
            server = smtplib.SMTP(f'smtp.example.com', 587)
            server.starttls()
            server.login(f'noreply@boardgamecreator.com', f'password')
            text = msg.as_string()
            server.sendmail(f'noreply@boardgamecreator.com', email, text)
            server.quit()
            print(f'Email sent successfully to {email}', flush=True, end=f'\n')
        except Exception as e:
            print(f'Failed to send email: {e}', flush=True, end=f'\n')