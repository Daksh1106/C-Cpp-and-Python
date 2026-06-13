"""
Lecture 3: Exceptions

Covers:
- Exceptions
- Runtime Errors
- try
- except
- else
- Functions
- pass
"""

# ==================================================
# 1) SYNTAX ERROR
# Error before the program even runs
# ==================================================

# Missing quotation mark
# print("hello, world)

# Python will raise a SyntaxError

# ==================================================
# 2) RUNTIME ERROR
# Program runs, but user enters bad input
# ==================================================

x = int(input("What's x? "))
print(f"x is {x}")

# If user enters "cat"
# ValueError occurs

print()

# ==================================================
# 3) TRY AND EXCEPT
# Handle invalid input
# ==================================================

try:
    x = int(input("What's x? "))
    print(f"x is {x}")
except ValueError:
    print("x is not an integer")

print()

# ==================================================
# 4) IMPROVEMENT
# Only put risky code inside try
# ==================================================

try:
    x = int(input("What's x? "))
except ValueError:
    print("x is not an integer")

# Problem:
# x may not exist if conversion fails

# print(f"x is {x}")

print()

# ==================================================
# 5) ELSE
# Runs only if try succeeds
# ==================================================

try:
    x = int(input("What's x? "))
except ValueError:
    print("x is not an integer")
else:
    print(f"x is {x}")

print()

# ==================================================
# 6) KEEP ASKING UNTIL VALID INPUT
# Use a loop
# ==================================================

while True:
    try:
        x = int(input("What's x? "))
    except ValueError:
        print("x is not an integer")
    else:
        break
print(f"x is {x}")

print()

# ==================================================
# 7) CREATE A FUNCTION
# Reuse the logic anywhere
# ==================================================

def main():
    x = get_int()
    print(f"x is {x}")

def get_int():
    while True:
        try:
            x = int(input("What's x? "))
        except ValueError:
            print("x is not an integer")
        else:
            break
    return x
main()

print()

# ==================================================
# 8) IMPROVEMENT
# Return directly instead of break
# ==================================================

def main():
    x = get_int()
    print(f"x is {x}")

def get_int():
    while True:
        try:
            x = int(input("What's x? "))
        except ValueError:
            print("x is not an integer")
        else:
            return x
main()

print()

# ==================================================
# 9) EVEN SHORTER VERSION
# Return immediately
# ==================================================

def main():
    x = get_int()
    print(f"x is {x}")

def get_int():
    while True:
        try:
            return int(input("What's x? "))
        except ValueError:
            print("x is not an integer")

main()

print()

# ==================================================
# 10) PASS
# Ignore the error and ask again
# ==================================================

def main():
    x = get_int()
    print(f"x is {x}")

def get_int():
    while True:
        try:
            return int(input("What's x? "))
        except ValueError:
            pass
main()

print()

# ==================================================
# 11) FINAL VERSION
# Pass prompt as an argument
# ==================================================

def main():
    x = get_int("What's x? ")
    print(f"x is {x}")

def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            pass
main()