# # Intro to Object Oriented Programming - Crash Course

https://www.youtube.com/watch?v=SiBw7os-_zI

### What are primitive data types

- variables that store single values (byte, int, float, bool, char)
- it created the struct or arrays - which allows you to store data together
- structs: allow you to store different types of data

 for example

 a knight struct (chess piece)
 can store things like isCaptured, color, location
 a struct can also store other structs

issue: you can't define functions within a structure

hence you can't write the move function with a chess board

### What are Objects?

- objects are instances of a class
- classes are a tempalte for objects 

example

class Knight 

has a move() method and position and color variables 

- knight class represents any given knight
- knight object represents a singular knight

### What is OOP?

- a way to create complex programs by grouping together related data and functions
- has four main principles: encapsulation, abstraction, inheritance, polymorphism

### Encapsulation

- a way to bundle data with methods that can operate on that data within a class
- members of other classes can interact with the attributes of another object through its methods
- methodes are the functions defined within the class
- Getters (retrieve information) and setters (allows values to be validated)
- the setting method allows both attributes to be changed as they should, rather than requiring you to individually change them
- you may sometimes want some attributes to be only "read only" from the outside
- so you would define a getter method but not a setter method : ie the variable could only be referenced, not changed
- it allows information hiding - so external classes would not directly edit an object's attributes
- each piece should not have access to or rely on the inner workings of other sections of code

### Abstraction
We care about Interface. Not the implementation behind the hood.

### Inheritance
Extending classes... Access modifiers: public, private, modifier

### Polymorphism
nterface / Implements in Java ... Same methods' name, but different implementations of methods.
