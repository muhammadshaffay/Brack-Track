# Brack-Track
Brack-Track : a C++ algorithm to track and match brackets, ensuring properly nested parentheses in strings

A common problem for compilers and text editors is to determine if the parentheses (or other brackets) in a string are balanced and properly nested. For example, the string “((())())()” contains properly nested pairs of parentheses , but the string “)()(“ and the string “())” does not contain properly matching parenthesis.


a. Give an algorithm that returns true if a string contains properly nested and balanced parentheses and false otherwise. Use an array to keep track of the number of left parentheses seen so far. (parenthesis())


b. Give an algorithm that returns the position in the string of the first offending parenthesis if the string is not properly nested and balanced. That is, if an excess right parenthesis is found, return its position; if there are too many left parentheses, return the position of the first excess left parentheses. Return -1 if the string is properly balanced and nested. Use a stack to keep track of the number and positions of left parentheses seen so far. (excess())
