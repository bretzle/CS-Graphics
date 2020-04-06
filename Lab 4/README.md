# Lab 4: Shape Classes and Container

## Introduction

The purpose of this lab is to create a class hierarchy and take advantage of the polymorphism features of C++, and an STL-based container class for the polymorphic shapes.

## Outcomes Addressed

- define and use two-dimensional and three-dimensional graphic object representations
- discuss and apply concepts of object-oriented programming, inheritance, polymorphism, and event-driven systems
- be familiar with C++ and STL concepts, including classes and constructors, operator overloading, STL vector class, dynamic memory with new and delete
- apply data structures to the management of computer graphics entities
- compiling and executing C++ programs on the Linux platform

## Background

The field of computer graphics lends itself quite well to the use of base and derived classes. The ability of derived classes to inherit properties from a base class so that they do not have to be rewritten is quite powerful. In addition, the ability to override and customize methods from the base class and to add new methods allows a derived class to customize itself for its own needs.

For this lab we will be creating a small hierarchy of classes to represent graphics entities. Inheritance will be key in thatit will allow us to ***reuse*** various properties and behaviors, as well as use polymorphism to treat all entities consistently regardless of their actual type.

As an example, consider the concept of a geometric “shape.” It is easy to envision that the shape has some properties, such as color, location on the screen, etc. However, how do you draw a shape?

Of course, we could establish a “type” property in our shape class, and then have a switch/case in our shape's draw method to call the correct drawing algorithm. This approach is, however, definitely not object-oriented. In fact, the need to draw uniquely based on the type of derived shape object is the exact situation that motivates “virtual” functions.

So, we will create an abstract base class, shape, placing all common properties and behaviors in this class (color, location), and derive a concrete class for each actual shape we wish to represent. The concrete classes will contain any additional properties needed by that shape (i.e. a circle needs a radius, but a line doesn't) as well as the behaviors specific to that concrete shape, such as how to draw itself.

Once we have a Shapes-class hierarchy working, we need a way to store a collections of shapes that will form a drawing or an image. Since any given image will containan unknown number of shapes, an array would not be appropriate. Rather, we should turn to a more advanced data structure. The C++ standard library offers a variety oftemplateddata structures for our use. This portion of the C++ standard library is oftenreferred to as the “Standard Template Library,” or, STL.

Templates in C++ have a syntax similar to generics in Java. While the mechanism is quite different, the syntax and end results are similar. The easiest STL data structure to understand and use is std::vector, which presents as agrowablearray similar to Java'sArrayList.

The next issue is what does the vector store? As seen in lecture, we cannot store Shape objects because vectors store by value. Thusslicingwould occur when adding Lines or Circles. Rather, our only choice is to store Shape*, which will allow all of our Shapes to be stored and handledpolymorphically. Since we are storing pointers, all memory management falls back on us. Alternatively, a best-practice available to us in C++11 and newer is to use std::unique_ptrorstd::shared_ptrwhen storing the object [pointers] into the container. We will do the former as it is the long-standing technique in C++ and worth experiencing.

## Lab Activities

The first step for this exercise will be to design your shapes hierarchy. As mentioned above you will be designing an abstract base class along with a few concrete classes. Starter code is not provided, the design is up to youper the requirements listed below. Read all of the requirements closely and use them to generate your design.Generating a UML diagram is suggested, but not required.Our design will support 3D, but we will initially be working in 2D, so the Z dimension can be ignored for a while–just set to 0 when not in use.

1. Design and implementthe abstract base class, Shape.
2. Design and document the following concrete Shape derivatives: Lineand Triangle. Circle, Rectangle, and Polygon are optional.
   - Have each derived shape contain different data members as appropriate (that parametrically define the object).
     - Common properties should be pushed to base classes.
     - Use floating point types (double or float) for all coordinates (preferably instances of Matrixas discussed above).
   - Implement all of the member functions. Use your code from Lab 2 to draw lines and circles. Rectangles and polygons should use line drawing.
   - Your Triangle classmuststore its three coordinates–not width and height, bounding box, etc.
3. Implement the image container class.
4. Develop a driver program for testing purposes. The driver program should
   - Be able to create multiple image objects (so you can thoroughly test copy and assignment) and add an arbitrary number of thederived shapes to the container.
   - Be able to make a new copy of an existing image (via the copy constructor). Note, in order to perform a deep copy, you will need to invoke the clone() method(s) in the shape derived classes.
   - Be able to assign the contents of one image to another (using the assignment operator). The contents of the target image must be destroyed correctly.
   - Be able to write an arbitrary image to file (using « or in/out via istream/ostream). Note -one image per file.
   - After closing your program and restarting it, be able to read an image from a file.
   - Thoroughly test all of the methods in the image class to make sure they work correctly. Pay special attention to the cases ofwhen you copy an image (either through the copy constructor or operator= ) and then destroy the original, because if you don't correctly implement deep copying, you'll see big problems. This will help test your clone() methods (in the shape derived classes); i.e., to make sure you didn't just copy a pointer (shallow copy), but rather copied the entire object (deep copy).

## Deliverables

This lab will span two weeks:
Week 4: 

- assignment made.

Week 5: submit pdf with completed 

- line.cpp 
- triangle.cpp
- shape.cpp

Week 6:

- pdf with all code
- zip of all code + Makefile