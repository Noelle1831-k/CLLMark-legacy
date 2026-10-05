def dashboard():
    if "username" not in session:
        return redirect(url_for("login"))
    transactions = Transaction.get_all_transactions()
    return render_template("dashboard.html", transactions=transactions)