# Introduction

In this Project you'll implement a fully functional, templated vector
class in C++. Much of the functionality that you need for the vector
class has been developed in your lab and homework assignments over the
past couple of weeks. You just need to pull it all together into a
complete Vector class.

(add information about lab submission)

As part of the lab, we are providing you with the header for the Vector
class with all the function declarations. Your job will be to fill in
the needed functionality and member variables. You may add any private
helper functions as needed to implement the class but you should not
change the given definitions. The vector class contains the following
public functions:

-   A default constructor

-   A constructor that takes an initial size

-   A copy constructor that takes another vector as its parameter

-   push_back()

-   pop_back()

-   at()

-   operator\[\]

-   size()

-   empty()

-   insert()

-   erase()

-   resize()

-   swap()

-   The assignment operator (=)

-   toString()

-   The equality operator (==)

A vector has three internal member variables:

-   capacity -- the size of the internal data array and maximum number
    of elements the vector can currently hold

-   size -- the actual number of elements filled in the array,

-   data -- a pointer of the data type that points to the data array

You will need to create these data members and keep them properly
updated as you build the class.

Templated classes are typically implemented completely in their header
file so that is what we'll be doing for this project. Just write the
functionality directly into the file we have provided, you will not need
a Vector.cpp file. Work through the various parts of the project below
to build out your class.

# Part 0 (10 pts) - Lab Setup

Start by creating a new program and getting it to compile. You'll need
the Vector.h file and a main.cpp to contain your main() function that
you'll use to test the Vector class as you write it. You'll also need to
create a Makefile to build the program.

In your main.cpp, #include the Vector.h file and, in the main()
function, create vector of integers. If you don't actually use the
template class, the compiler will not try to compile and use it and so
you won't get any error messages.

If you try to compile now, it should fail as interface we've given you
is just the declarations and you haven't implemented and of the
functions. Fix this by stubbing out all of the functions in the class
interface. For void functions, just replace the semicolon (;) at the end
of the line with open and close curly braces ({}). For functions that
have a return type, return a default null value. Once your program
compiles, you are ready to move on and start implementing the class.

# Part 1 (10 pts) -- Basic constructor, toString(), & push_back()

Let's start by getting the basic constructor working along with the
push_back() and toString() methods so we can see changes in the vector.

The first thing you have to do is add data members to the class. Add a
private section and declare the data variables that the class will need
to function.

Next, implement the constructor. For this class we will create a single
constructor that can take an initial size for the vector which is also a
default parameter so that it can function as the default constructor for
the class if no size is specified. The constructor should set capacity
to the size passed in, set the size variable to zero (since the vector
is empty), and dynamically create a data array equal to the capacity
parameter and store that with a pointer.

After you've got the constructor working, implement the push_back()
method. This takes as input a value of the type the vector holds, adds
it to the end of the data in the array, and increments the size
variable.

Finally, implement the toString() medhod. This should just return a
space separated list of the items in the vector. For example, if we had
a vector of integer that contained the values 10, 5, 90, -12, & 7 the
string returned from toString would look like this:

"10 5 90 -12 7"

Once you've implemented these functions, write some code in main.cpp
that tests out the functions you've written. What happens if you try to
call push_back() more times that your initial capacity? We'll deal with
properly handling that situation in a later part of the project.

# Part 2 (10 pts) -- size(), empty(), and pop_back()

Next let's get a few of the easy methods out of the way by implementing
the size(), empty() and pop_back() methods.

-   size() -- this method returns the current number of elements stored
    in the vector.

-   empty() -- this method returns true if the vector has no data and
    false otherwise.

-   pop_back() -- this method removes the last element from the vector
    and reduces the size parameter to reflect the deleting of the item.

After implementing these methods, add some test code to your main.cpp to
verify that they are working.

# Part 3 (10 points) -- Data retrieval, at() and \[\]

Now that we can put data into the vector and check its size, it would be
nice to retrieve the data in the array. We'll implement four functions
here. The "legacy" square bracket accessors that mimic array
functionality, and the at() method that does range checking.

There are two forms of each of these methods, a const version and a
non-constant version. The constant version is used anytime the element
return is not going to be modified, such as when the value is used in an
expression or on the right-hand side of an assignment operator. Being
const, the compiler can optimize some of the code. The other version is
used when we want to access the actual memory of the item so we can
change or updated it such as when it is used on the left-hand side of
the assignment operator. You can write the non-constant version of each
method and then have the constant versions return the results of that
function. That way, you only have to write the logic of each method once
and don't have it repeated in two different places.

The operator\[\]() method should just return value at the index provide
in the function call, without checking that it is a valid index that
actually lies within the data stored in the vector. The at() function on
the other hand, should validate that the index specified is valid. If it
is, it returns the value at that index. If not, it should throw a C++
out_of_range exception. You get this exception by including the
stdexcept header and its constructor requires a string to be passed as a
message. We've provided the string as a constant at the top of the
Vector.h file. Just pass that constant to the out_of_range constructor.
If you were writing your own program, you could have this say anything
including telling the user what the index was and what the size was but
for testing purposes in class, we'll have everyone display the same
message.

Once you've completed these methods, add code to your main.cpp to verify
that they are working properly

# Part 4 (10 pts) -- Changing the vector's size

Now that we can add and retrieve data, it's time to revisit the issue of
what to do when we try to add another element when the internal data
array is full. We're going to start by writing our resize() method. This
method takes a new size and adjusts the capacity of the vector to that
new size. This method is not, by default, data safe. If the new size is
smaller than the filled part of the data array, the data beyond that
position will be lost. This method should do the following:

-   create a new data array with a size equal to the value passed to the
    method

-   if size \< new_size, copy over all the elements of the existing
    array, else copy only the first new_size elements over and set size
    to the smaller of size or new_size

-   set capacity = to new_size (the parameter passed to the method)

-   delete the old data array

-   set the data pointer member variable to point to the new array

That should look fairly similar to the grow() function from Homework 2.

Now that we can change the size of the data array, we need to handle the
case in push_back() where we want to add a new element when the array is
full. Modify your push_back() method to do the following:

-   if current size is less than capacity, add the item as we already
    do.

-   If current size is equal to capacity (i.e. the array is full), call
    the resize() function you wrote above with a size larger than
    capacity and then add the new item to the new, larger array.

The only question is how much to grow the data array by in each step.
We're only adding one element so we could just grow it by one. But then
when we add another element, we'll have to grow it again. Growing the
array is an "expensive" operation because it copies all the elements
from the old array to the new one. In Big O terms, which we'll talk
about in a week or two, it is O(n) which means it scales as the size of
the data set. We don't want to be doing this with every insertion,
that's not very efficient. By convention, we double the size of the
array each time we need to grow it. So when we call our resize() method
to grow the array, we pass in the current capacity times 2. By doing
this, we reduce the cost from O(n) to what is called amortized constant
time. Meaning we have to do n operations but only once every n calls.
So, it averages out and is much more efficient. More on that when we get
to Big O in a couple of weeks.

Once you have these methods implemented, add some test code to your main
function to verify that they are working.

# Part 5 (10 pts) -- Inserting

The next step is to be able to insert data at arbitrary positions in the
data array. To do this we are going to implement our insert() function
that takes an index and a value to insert. This should look familiar to
the insert() function you did in Lab 3. This function should do the
following:

-   Validate that the index is within the data (or at the end). If not,
    is should throw an out_of_range exception.

-   Check to see if the data array is full. If it is, it should resize
    it to double its current capacity.

-   Move all the elements beyond the insertion point over a position

-   Add the new data item

-   Update the size member variable

Add code to your main() function to verify that your insert function is
working properly.

# Part 6 (10 pts) -- Erasing

In addition to inserting data at an arbitrary location, we want to be
able to remove data. This is done in our erase() method which just takes
a position as its argument. This method should:

-   Validate that the index is within the data. If not, it should throw
    and out_of_range exception.

-   Remove the item at the specified position and shift all the elements
    beyond that point over one so there is no gap in the data.

-   Update the size member variable to reflect the change

This one is a bit easier than insert. You don't really have to do
anything to remove the specified element, you can just copy the next one
over into its position. And you don't have to worry about increasing the
size of the data array.

Once you've implemented the method, write some code in main() to verify
that it's working properly.

# Part 7 (10 pts) -- The assignment operator, copy constructor, & destructor

Since we're working with dynamic memory in the form of our data array,
we need to add an assignment operator and copy constructor to our class
as well as a destructor (The Rule of Three)

Let's start with the destructor as that's the easiest. Remember the role
of the destructor is to free up any dynamically allocated memory that
the class is responsible for (whether it allocated the memory or not).
In our case, we're responsible for our data array and our destructor
should delete it. It's a one-line function but very important in
preventing memory leaks. Add the destructor to your class.

Next let's tackle the assignment operator. If we don't write this, the
compiler will write one for us but weird (i.e. bad) things will happen
if we make a copy of our object. By default, the program will make a new
vector object, and copy over the data members. Doesn't sound too bad,
right. But remember, one of our data members is a pointer. So what gets
copied is the pointer value, the memory address, not the underlying data
it is pointing at. This is a "shallow" copy and now our two vectors will
be pointing at the same data. If one of them updates it, the data vector
will change in both of them but the size (and possibly the capacity)
will change only in the one that made the change, not the other. This is
not what we want. The copy constructor should do the following:

-   Copy the size and capacity from the passed in object.

-   Create a new data array in the current object (the one being create)
    and copy over all the items from the data array in object passed in.

Now we've made a deep copy and the two vectors are completely
independent. You need to be careful when creating that new data array to
verify that the current vector doesn't already have one. And if it does,
you need to delete it before making the new one or you'll get a memory
leak.

With the assignment operator done, the copy constructor is a one-line
function. It does the exact same operation but is invoked when a vector
is passed as the argument to the constructor instead of when an
assignment operation is called. With the assignment operator written, we
can just invoke it in the copy constructor. Here's the full function:

Vector(Vector\<T\>& other){

\*this = other;

}

We just deference the this pointer to get the current object, and assign
it the other vector. That way we only have the logic for this deep copy
in one location (the assignment operator).

Now go add code to main() to test out the various copy methods and
verify that you got actual copies instead of multiple objects pointed at
the same data.

# Part 8 (10 pts) -- Swapping vectors

The last step is to write our swap() method. When we swap two vectors,
we are exchanging the contents of one with the contents of the other. At
its most basic level a swap is just three operations:

1.  Create a temporary object and copy object A to that

2.  Set object A to object B

3.  Set object B to the temporary object

So we could just write code that looks like this:

vector\<T\> tmp = \*this;

\*this = other;

other = tmp;

and take advantage of our assignment operator. But if we think about our
data structure, that's inefficient as we are copying all the data from
both vectors. We don't need to do that as the data is just sitting in a
dynamically allocated array that we have a pointer to. So instead of
using our assignment operator, we're going to write custom code to do
this more efficiently and skip the copy. Take a moment to think about
how we might do that before reading the next bit. And then see if you
had the correct idea.

Instead of using the assignment operator, we need to swap each data
member individually. That way we just swap the value of the pointers
(i.e. the location they are pointing to) instead of having to make the
expensive copy of both arrays. We can make a temp size_t variable and
swap the size and the capacity, and then make a temp pointer and swap
the data pointers. That's all that is needed. In this case, nine quick
operations instead of two potentially huge copies of large arrays.

Write some test code to make sure the swaps are working properly and the
vectors function properly afterwards.

# Part 9 (10 points) -- Equality

The last thing we need to do is to implement the equality operator (==)
so that we can compare two vectors. The function signature for the
equality operator, as given in the header file is:

bool operator==(const Vector\<T\> & other);

It takes in a constant reference to another vector (the vector on the
right hand side of the operator) and returns a Boolean. There are two
things that you need to check for equality and a third that you can
check for efficiency.

1)  (optional) Are we comparing the same object (i.e. this == &other).
    If so, return true.

2)  Does the vector have the same number of elements. If not, return
    false.

3)  Is each element in the data array of the two vectors equal on an
    index by index basis? If so, return true, otherwise return false.

Implement the equality operator for your vector class and add some test
code to your main to verify that it is working properly.

# Part 10 (10 points) -- Check for memory leaks

If you haven't been already, run valgrind on the program you've written
along the way to test everything. You may also want to add in some more
code that explicitly creates and deletes some vectors (either
dynamically, as part of functions, or both) so that it exercises your
destructor and other operations that should be creating and deleting
memory. If you did everything properly, you should have no memory leaks.
If you do, track them down and fix them.

# Submit your code

That's it. You now have a perfectly functional vector class. To submit
your code, you will just submit your Vector.h file. We have a main.cpp
to test your class. It will run a series of tests and give you points
based on the point value of the various parts above.
