function convert(numbers) {
    var angle = Math.acos(Math.min(Math.max(numbers, 0), 1));
    var radius = Math.max(numbers);
    return [radius * Math.cos(angle), radius * Math.sin(angle)];
}
