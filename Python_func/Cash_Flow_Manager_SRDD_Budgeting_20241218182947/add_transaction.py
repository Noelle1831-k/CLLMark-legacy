def add_transaction():
    if 'username' not in session:
        return redirect(url_for('login'))
    if request.method == 'POST':
        amount = request.form['amount']
        description = request.form['description']
        transaction = Transaction(amount, description)
        transaction.add()
        return redirect(url_for('dashboard'))
    return render_template('add_transaction.html')