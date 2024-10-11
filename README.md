What to submit: your Github repository URL. Commit and push your code every ten minutes when coding this assignment.

Start with the Chair class code we used in this module's lessons: 210-demo-chair-1.cppDownload 210-demo-chair-1.cpp

This code features a Chair class. The private member variables are legs (an integer) and prices (a double array). It has a default constructor and a parameter constructor. 

Review the rest of the class carefully to note the setters, getters, and two additional class methods that are defined.

The main() function creates Chair objects in several different ways:

First, by creating a default Chair object (line 55) and calling its setters to populate the object's data.
Second, by creating a Chair object (line 61) using the parameter constructor. It then calls a setter to set the object's price data.
Finally, by creating an array of Chair objects (line 68). Each object has its setter methods called to populate the data.
Amend the code as follows:

Change the default constructor. Instead of it assigning null values, we want it to randomly select 3 or 4 legs, and to randomly select prices (including dollars and cents) from $100.00 to $999.99.
Change the parameter constructor. Now it has just one parameter, the number of legs. Make it have two parameters: number of legs, and an array of 3 doubles (the prices).
In the third code block (starting at line 67), amend this such that the default constructors are used to populate these objects.
Exercise your changes in main() with clear, easy-to-understand output.

Hint: random doubles? Sure! Try:

const int MIN = 10000, MAX = 99999;
double price = (rand() % (MAX-MIN+1) + MIN) / (double) 100;
