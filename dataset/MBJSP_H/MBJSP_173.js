function removeSplchar(text) {
    return text.replace(/[^a-zA-Z0-9\u2028\u2029\u00a0-\uffff]/g, "");
}
