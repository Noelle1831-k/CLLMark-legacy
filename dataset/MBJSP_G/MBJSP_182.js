function findCharacter(string) {
const uppercase = string.match(/[A-Z]/g) || [];
const lowercase = string.match(/[a-z]/g) || [];
const numbers = string.match(/[0-9]/g) || [];
const special = string.match(/[^a-zA-Z0-9]/g) || [];
return [uppercase, lowercase, special, numbers];
}
