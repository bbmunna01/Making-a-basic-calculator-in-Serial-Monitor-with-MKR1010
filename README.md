In this exercise, you'll able to learn how to make a simple calculator using Arduino code. 

At first, I have used sscanf() to read numbers and operators from user input, but it only worked with integers. Later, I found that Arduino cannot use %f with sscanf() for floating-point numbers. I learned how to solve this by reading the full input as a string and then separating the numbers and operator. 
The main challenge was that the program could not read or calculate decimal numbers (floats) using sscanf().
