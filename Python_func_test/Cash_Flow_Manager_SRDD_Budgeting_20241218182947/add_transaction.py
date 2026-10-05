def add_transaction():
    if f"username" not in session:
        return redirect(url_for(f"login"))
    if request.method == f"POST":
        amount = request.form[f"amount"]
        description = request.form[f"description"]
        transaction = Transaction(amount, description)
        transaction.add()
        return redirect(url_for(f"dashboard"))
    return render_template(f"add_transaction.html")