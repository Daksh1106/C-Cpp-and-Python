"""
Lecture 0: Creating Code with Python

Covers:
- hello world
- functions
- bugs
- variables
- comments / pseudocode
- strings and parameters
- formatting strings
- stripping and title case
- integers and floats
- rounding and formatting
- def
- returning values
"""

# ==================================================
# 1) FIRST PROGRAM
# ==================================================

# Start: the classic first program
print("hello, world")

print()

# ==================================================
# 2) FUNCTIONS
# ==================================================

# print() is a function
print("Functions are actions the computer can do")

print()

# ==================================================
# 3) BUGS
# ==================================================

# A missing bracket would cause an error
# print("hello, world"

print("Bugs are normal and help you learn")

print()

# ==================================================
# 4) INPUT AND VARIABLES
# ==================================================

# Ask the user for their name
name = input("What's your name? ")

# Print a simple greeting
print("hello, world")

print()

# Variable stores the user input
name = input("What's your name? ")

# Wrong way: prints the word name, not the variable
print("hello, name")

# Better: print the variable on a new line
print("hello,")
print(name)

print()

# ==================================================
# 5) COMMENTS AND PSEUDOCODE
# ==================================================

# Ask the user for their name
name = input("What's your name? ")

# Print hello
print("hello,")

# Print the name
print(name)

print()

# ==================================================
# 6) STRING FORMATTING
# ==================================================

# Use + to join strings
name = input("What's your name? ")
print("hello, " + name)

# Use comma to pass multiple arguments
print("hello,", name)

# Use end="" to avoid a new line
print("hello,", end="")
print(name)

# f-string: cleanest style
print(f"hello, {name}")

print()

# ==================================================
# 7) QUOTATION MARKS
# ==================================================

# This would break:
# print("hello,"friend"")

# Use escaped quotes when needed
print("hello, \"friend\"")

print()

# ==================================================
# 8) STRIP, TITLE, AND CHAINING
# ==================================================

# Remove extra spaces
name = input("What's your name? ").strip()
print(f"hello, {name}")

# Capitalize properly
name = input("What's your name? ").strip().title()
print(f"hello, {name}")

print()

# ==================================================
# 9) INTEGERS AND CALCULATOR
# ==================================================

# Without casting, input stays text
x = input("What's x? ")
y = input("What's y? ")

# This would join strings, not add numbers
# print(x + y)

# Cast to int to add correctly
x = int(input("What's x? "))
y = int(input("What's y? "))
print(x + y)

print()

# ==================================================
# 10) FLOATS
# ==================================================

x = float(input("What's x? "))
y = float(input("What's y? "))

print(x + y)

# Round to nearest whole number
z = round(x + y)
print(z)

# Add commas
print(f"{z:,}")

print()

# Division
x = float(input("What's x? "))
y = float(input("What's y? "))

z = x / y
print(z)

# Round to 2 decimal places
print(round(x / y, 2))

# f-string formatting to 2 decimal places
print(f"{x / y:.2f}")

print()

# ==================================================
# 11) DEFINING YOUR OWN FUNCTION
# ==================================================

def hello():
    print("hello")

hello()

print()

# Function with one parameter
def hello(to):
    print("hello,", to)

name = input("What's your name? ")
hello(name)

print()

# Default argument
def hello(to="world"):
    print("hello,", to)

hello(name)
hello()

print()

# ==================================================
# 12) main()
# ==================================================

def main():
    name = input("What's your name? ")
    hello(name)
    hello()

def hello(to="world"):
    print("hello,", to)

main()

print()

# ==================================================
# 13) RETURNING VALUES
# ==================================================

def main():
    x = int(input("What's x? "))
    print("x squared is", square(x))

def square(n):
    return n * n

main()