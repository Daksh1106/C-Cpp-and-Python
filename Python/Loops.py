"""
Loops
Covers:
- while loops
- for loops
- input validation
- functions
- lists
- len()
- dictionaries
- list of dictionaries
- Mario patterns
"""

# ==================================================
# 1) LOOPS: from repeated print() to while loop
# ==================================================

# Start: same line repeated 3 times
# print("meow")
# print("meow")
# print("meow")

# Better: use a while loop
i = 0
while i < 3:
    print("meow")
    i += 1   # same as i = i + 1

print()

# ==================================================
# 2) FOR LOOP: from while loop to cleaner loop
# ==================================================

# Start: list of numbers
# for i in [0, 1, 2]:
#     print("meow")

# Better: range(3) gives 0, 1, 2 automatically
for _ in range(3):
    print("meow")

# Another short form
print("meow" * 3)

# Separate lines
print("meow\n" * 3, end="")

print()

# ==================================================
# 3) USER INPUT: from infinite loop to validation
# ==================================================

# Start: keep asking until n is valid
while True:
    n = int(input("What's n? "))
    if n > 0:
        break

# Use the valid number
for _ in range(n):
    print("meow")

print()

# Better: use functions
def main():
    meow(get_number())

def get_number():
    while True:
        n = int(input("What's n? "))
        if n > 0:
            return n   # send the value back

def meow(n):
    for _ in range(n):
        print("meow")

# ==================================================
# 4) LISTS: from manual indexing to looping
# ==================================================

students = ["Hermione", "Harry", "Ron"]

# Start: print each item by index
# print(students[0])
# print(students[1])
# print(students[2])

# Better: loop through the list
for student in students:
    print(student)

print()

# ==================================================
# 5) len(): from simple list to numbered output
# ==================================================

for i in range(len(students)):
    print(i + 1, students[i])

print()

# ==================================================
# 6) DICTIONARIES: from two lists to key-value pairs
# ==================================================

# Start: two separate lists
# students = ["Hermione", "Harry", "Ron", "Draco"]
# houses = ["Gryffindor", "Gryffindor", "Gryffindor", "Slytherin"]

# Better: one dictionary
students = {
    "Hermione": "Gryffindor",
    "Harry": "Gryffindor",
    "Ron": "Gryffindor",
    "Draco": "Slytherin",
}

# Print keys only
for student in students:
    print(student)

print()

# Print key and value
for student in students:
    print(student, students[student], sep=", ")

print()

# ==================================================
# 7) LIST OF DICTIONARIES: more data per student
# ==================================================

students = [
    {"name": "Hermione", "house": "Gryffindor", "patronus": "Otter"},
    {"name": "Harry", "house": "Gryffindor", "patronus": "Stag"},
    {"name": "Ron", "house": "Gryffindor", "patronus": "Jack Russell terrier"},
    {"name": "Draco", "house": "Slytherin", "patronus": None},
]

for student in students:
    print(student["name"], student["house"], student["patronus"], sep=", ")

print()

# ==================================================
# 8) MÁRIO: from repeated blocks to functions
# ==================================================

# Start: repeated prints
# print("#")
# print("#")
# print("#")

# Better: loop
for _ in range(3):
    print("#")

print()

# Better: function for a column
def print_column(height):
    for _ in range(height):
        print("#")

print_column(3)

print()

# Row: print horizontally
def print_row(width):
    print("#" * width)

print_row(4)

print()

# Square: rows + columns
def print_square(size):
    for _ in range(size):
        print_row(size)

print_square(3)