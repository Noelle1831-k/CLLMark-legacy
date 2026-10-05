function palindromeLambda(texts) {
    return texts.filter(item => item.length > 0 && item.charAt(0) == item.charAt(item.length - 1));
}
