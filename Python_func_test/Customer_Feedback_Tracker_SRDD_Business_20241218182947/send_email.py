def send_email():
    '''
    Distribute feedback forms via email.
    '''
    print('Sending feedback form via email...')
    sender_email = 'your_email@example.com'
    receiver_email = input('Enter recipient email: ')
    subject = 'Feedback Form'
    body = 'Please fill out the feedback form attached.'
    msg = MIMEText(body)
    msg['Subject'] = subject
    msg['From'] = sender_email
    msg['To'] = receiver_email
    try:
        with smtplib.SMTP('smtp.example.com', 587) as server:
            server.starttls()
            server.login(sender_email, 'your_password')
            server.sendmail(sender_email, receiver_email, msg.as_string())
        print('Email sent successfully.')
    except Exception as e:
        print(f'Failed to send email: {e}')