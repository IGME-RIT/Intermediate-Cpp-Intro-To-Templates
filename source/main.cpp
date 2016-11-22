/*
Intro To Templates
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <iostream>
#include <string>
using namespace std;

// Sometimes, you'll run into a situation where you need to write the same code over again for different types.
// Take this function for example:

// Takes two numbers and prints out the halfway point between them.
void PrintMidpoint(const int a, const int b)
{   
    cout << (a + b) / 2 << endl;
}

// If I want this to work with floats, I have to write an overloaded function.
void PrintMidpoint(const float a, const float b)
{
    cout << (a + b) / 2 << endl;    // Notice how the code inside the function is the same.
}

// Templating allows us to write both of these functions at the same time!

template<class SomeType>                                // This declares the temporary type we will use with our function.
void PrintMidpointTemplated(const SomeType a, const SomeType b)     // SomeType is used as the type for our passed in parameters.
{
    cout << (a + b) / 2 << endl;                        // The code inside the function will be the same regardless of the type used.
}

// How does this work?
// On its own, this template does nothing at all. There is no actual fuction.
// Instead, the compiler waits for the function to be used, and creates a function for us.
// This saves us the frustration of needing to write a new function every time we need to do the same old thing with a new type.



// What if we want to write a function that takes in two different types? Easy:
template<class TypeA, class TypeB>                  // Just declare more types in this list like so.
void PrintTwoThings(const TypeA a, const TypeB b)
{
    cout << a << " " << b << endl;
}


// Slightly more useful than the previous examples, we can use templated functions for arrays of objects.
template<class Type>
void PrintArray(const Type * const arrayToPrint, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arrayToPrint[i] << " ";
    }
    cout << endl;
}



// Start of main function
int main() 
{

    {
        // Here we can test calling some basic templated functions.
        // test integers
        cout << "PrintMidpointTemplated(1, 4);" << endl;
        PrintMidpointTemplated(1, 4);

        // test floats
        cout << "PrintMidpointTemplated(1.f, 4.f);" << endl;
        PrintMidpointTemplated(1.f, 4.f);

        // test chars
        cout << "PrintMidpointTemplated('a', 'c');" << endl;
        PrintMidpointTemplated('a', 'c');


        //      What if our types don't match? (this line won't compile)
        // PrintMidpointTemplated(1, 1.5);

        // Templates allow you to specify the type with the funciton call.
        cout << "PrintMidpointTemplated<float>(1, 1.5); " << endl;
        PrintMidpointTemplated<float>(1, 1.5);


    }
    cin.get();

    {
        // Test using a templated function that takes multiple types

        PrintTwoThings("pi:", 3.14159);

        PrintTwoThings("Hello,", "World!"); // There's nothing stoping both types from being the same.
    
        PrintTwoThings<char, char>(79, 75); // We can specify multiple types like this!
    }
    cin.get();


    {
        // Test our templated array printing function.
        int i[] = { 1, 2, 3, 4, 5 };
        PrintArray(i, sizeof(i) / sizeof(int));

        // Test our templated array printing function.
        float f[] = { 1.f, 2.1f, 3.21f, 4.321f, 5.4321f, 6.54321f, 7.654321f, 8.7654321f, 9.87654321f };
        PrintArray(f, sizeof(f) / sizeof(float));
        
        // We can print a string this way as well, since it's just an array of characters.
        char c[] = "print string test";
        PrintArray("print string test", sizeof(c));
    }
    cin.get();



    return 0;   // End Program.
}