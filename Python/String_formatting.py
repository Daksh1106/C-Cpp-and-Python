"""
Demonstration of various string formatting and manipulation techniques in Python.

This script covers:
- Different ways to print strings (concatenation, f-strings, commas)
- The end parameter in print()
- String methods: strip(), title()
- Method chaining
"""

# Get user input
name = input("What's your name? ")
print()

# --- Example 1: Using end parameter to suppress newline ---
print("\n--- Method 1: Using end parameter ---")
print("hello,", end="")
print(name)
print()

# --- Example 2: F-string formatting (modern approach) ---
print("--- Method 2: F-string (recommended) ---")
print(f"hello, {name}")
print()

# --- Example 3: Printing on separate lines ---
print("--- Method 3: Separate print statements ---")
print("hello,")
print(name)
print()

# --- Example 4: String concatenation with + operator ---
print("--- Method 4: String concatenation with + ---")
print("hello, " + name)
print()

# --- Example 5: Using comma separator ---
print("--- Method 5: Comma separator in print() ---")
print("hello,", name)
print()

# --- Example 6: Using strip() to remove whitespace ---
print("\n--- String Manipulation: strip() ---")
name_clean = name.strip()
print(f"After strip(): {name_clean}")
print(f"Greeting: hello, {name_clean}")
print()

# --- Example 7: Combining strip() and title() (two steps) ---
print("--- String Manipulation: strip() + title() (separate) ---")
name_clean = name.strip()
name_titled = name_clean.title()
print(f"After strip() and title(): {name_titled}")
print(f"Greeting: hello, {name_titled}")
print()

# --- Example 8: Method chaining (combining operations) ---
print("--- String Manipulation: Method Chaining ---")
name_formatted = name.strip().title()
print(f"After chaining strip().title(): {name_formatted}")
print(f"Greeting: hello, {name_formatted}")
print()

# --- Example 9: Combining input processing and output (one-liner) ---
print("--- All-in-one approach (most concise) ---")
greeting_name = input("What's your name? ").strip().title()
print(f"hello, {greeting_name}")