function areRotations(string1, string2) {
if (string1.length !== string2.length) return false;
return (string1 + string1).includes(string2);
}
