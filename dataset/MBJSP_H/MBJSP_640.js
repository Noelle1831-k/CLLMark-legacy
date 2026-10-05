function removeParenthesis(items) {
    let parent = items[0].replace(/\(([^\)]*)\)/g, '').trim();
    items.splice(0, 1);
    items.splice(0, 1);
    return parent;
}
