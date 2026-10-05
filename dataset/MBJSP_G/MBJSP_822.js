function passValidity(p) {
const hasUpper = /[A-Z]/.test(p);
const hasLower = /[a-z]/.test(p);
const hasDigit = /\d/.test(p);
const hasSpecial = /[!@#$%^&*(),.?":{}|<>]/.test(p);
const lengthOk = p.length >= 8;
return hasUpper && hasLower && hasDigit && hasSpecial && lengthOk;
}
