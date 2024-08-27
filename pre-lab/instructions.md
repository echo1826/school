For this lab, you will write a Student class and use a one-dimensional array of Student objects to
represent the students in a particular course. Finally, you will write a program that allows the user to
enter data about each student in the array, and then search the array to retrieve the data.
<br/>
<br/>
Begin by writing the Student class definition. The class should contain two data members: a name and
an ID number; you should choose appropriate types for each. The class should also contain the
following functions:
<ul>
    <li>
        Constructor: The constructor should take no arguments, and should set the instance's data
        members to suitable initial values.
    </li>
    <li>
        setData: This function should receive new values for both data members and assign the instance's
        data members appropriately.
    </li>
    <li>
        Accessor functions: These functions should return the current values for each data member, and
        should have appropriate names.
    </li>
</ul>

Write a simple main function that allows you to test your Student class thoroughly before continuing.
Once you are satisfied that your class is correct, write a main function that implements the following
steps.

<ol>
    <li>Declare an array of 3 Student objects</li>
    <li>For each student in the array, prompt the user to enter a name and an ID number</li>
    <li>Until the user wants to quit, do the following:</li>
    <ol style="list-style-type: upper-alpha">
        <li> 
            ask the user whether s/he wants to quit or to search the student list by name or by id
            number, and read in the response
        </li>
        <li>
            read in the name or ID number of the student to be found
        </li>
        <li>
            search the list of students and print the other piece of data (that is, if searching by
            name, print the student's ID number, and vice versa)
        </li>
        <li>
            if no matching student is found, print an error message
        </li>
    </ol>
</ol>

