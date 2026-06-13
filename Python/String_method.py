"""
String Methods

Covers:
- capitalize()
- title()
- strip()
- method chaining
- building a new list
- append()
- join()
"""

# ==================================================
# 1) STARTING DATA
# Notice the extra spaces and bad capitalization
# ==================================================

shows = [
    " avatar: the last airbender ",
    "BEN 10",
    "spongebob squarepants",
    " power rangers "
]

# Original program
for show in shows:
    print(show)

print()

# ==================================================
# 2) CAPITALIZE
# Only capitalizes the first character
# ==================================================

for show in shows:
    print(show.capitalize())

print()

# Example:
# "hello world" -> "Hello world"

# ==================================================
# 3) TITLE
# Capitalizes every word
# ==================================================

for show in shows:
    print(show.title())

print()

# Example:
# "hello world" -> "Hello World"

# ==================================================
# 4) STRIP
# Removes spaces from beginning and end
# ==================================================

for show in shows:
    print(show.strip())

print()

# Example:
# "  hello  " -> "hello"

# ==================================================
# 5) METHOD CHAINING
# First strip(), then title()
# ==================================================

for show in shows:
    print(show.strip().title())

print()

# Read as:
# Take show
# -> remove spaces
# -> title case it

# ==================================================
# 6) BUILD A NEW CLEAN LIST
# ==================================================

cleaned_shows = []

for show in shows:
    cleaned_shows.append(
        show.strip().title()
    )

print(cleaned_shows)

print()

# append() adds an item to the list

# ==================================================
# 7) PRINTING THE LIST DIRECTLY
# ==================================================

print(cleaned_shows)

print()

# Output contains:
# []
# quotes
# commas
# Python list formatting

# Not very user friendly

# ==================================================
# 8) JOIN
# Convert list into one string
# ==================================================

print(" ".join(cleaned_shows))

print()

# Space joins every element

# Example:
# ["A", "B", "C"]
# -> "A B C"

# ==================================================
# 9) BETTER JOIN
# Use comma and space
# ==================================================

print(", ".join(cleaned_shows))

print()

# Example:
# A, B, C

# ==================================================
# 10) FINAL VERSION
# ==================================================

cleaned_shows = []

for show in shows:
    cleaned_shows.append(
        show.strip().title()
    )

print(", ".join(cleaned_shows))