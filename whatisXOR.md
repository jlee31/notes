# What is xor

exclusive or
returns 1 or true if either is true but not both

### bitwise operations

T ^ F == 1
F ^ T == 1
T ^ T == 0
F ^ F == 0



``` javascript 
// you can swap values using xor
let a = 5, b = 3;
a = a ^ b;  // a becomes 6
b = a ^ b;  // b becomes 5
a = a ^ b;  // a becomes 3
// Now, a is 3 and b is 5 without using a temporary variable

```
