"""
Lecture 1: Conditionals
Covers:
- if, elif, else
- or, and
- modulo
- custom function
- match
"""

# Example 1: Comparing two numbers
x = int(input("What's x? "))
y = int(input("What's y? "))
if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")

print()

# Example 2: Grade using and
score = int(input("Score: "))
if score >= 90:
    print("Grade: A")
elif score >= 80:
    print("Grade: B")
elif score >= 70:
    print("Grade: C")
elif score >= 60:
    print("Grade: D")
else:
    print("Grade: F")

print()

# Example 3: Even or odd using modulo
n = int(input("What's x? "))
if n % 2 == 0:
    print("Even")
else:
    print("Odd")

print()

# Example 4: Custom function for parity
def main():
    n = int(input("What's x? "))
    if is_even(n):
        print("Even")
    else:
        print("Odd")
def is_even(n):
    return n % 2 == 0
main()

print()

# Example 5: match statement
name = input("What's your name? ")
match name:
    case "Harry" | "Hermione" | "Ron":
        print("Gryffindor")
    case "Draco":
        print("Slytherin")
    case _:
        print("Who?")