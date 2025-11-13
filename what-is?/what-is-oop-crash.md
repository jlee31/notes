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

Information Hiding / Keeping Data hidden from external classes - helps keep control of your program and prevent it from being too complicated

### Abstraction
We care about Interface. Not the implementation behind the hood.

- only showing essential details and keeping everything else hidden
- when driving a car, we know how to gas and brake pedals work, but we don't need to know all the nitty gritty like the engine
- the classes we create should be the car, the users should not worry about the details within the classes
- classes should not directly interact with other classes' data - rather they use methods to access data (connection to encapsulation)

think of interface and implementation

interface
- refers to the way sections of code can communicate with each other
- done typically with methods

implementation
- the implementations should be hidden

returning to chess example
- you want the knight piece and king piece to interact each other but not change the king piece
- it ensures programs are incremental, and not entangled/complex

### Inheritance
Extending classes... Access modifiers: public, private, modifier

- allows you to create classes from other classes

example:

- for a game, you can create a class named Action, with methods common to all weapons (like attack, or damage)
- subclasses like Sword and Clubs can have different values for their attributes, but can still take an attack and damage method
- it can create a hierarchy of different classes

- accesss modifiers change which classes have access to other classes, methods or attributes
1) Public
- can be accessed from anywhere in your program
- can be accessed inside the hierachy, as well as outside in the rest of the program
2) Private
- can only be accessed within the same class that the member is defined
3) Protected
- can be accessed within the class it is defined, as well as any subclasses of that class
- makes protected members private to the heirarchy in which they are defined 

### Polymorphism
Interface / Implements in Java ... Same methods' name, but different implementations of methods.

- describe methods that are able to take on many forms

1) dynamic polymorphism
- runs during runtime
- describes when a method signature is in oth a subclass and a superclass
- methods share the same name but have different parameters
- the subclass implemtation overrides the superclass

2) static polymorphism

- runs during compile=time
- when multiple methods with the same name but different arguments are defined in the same class
- method overloading: when methods can be differentiable by different number of parameters, different type of parameters or different order of parameters

overall

- polymorphism allows methods to take on different forms
