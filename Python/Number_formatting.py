"""
Demonstration of Python arithmetic operations and number formatting.

This script shows:
- Type conversion (string to float)
- Rounding numbers
- Formatting numbers with thousands separators
- Formatting decimal places using f-strings
"""

# Get two floating-point numbers from the user
x = float(input("What's x? "))
y = float(input("What's y? "))

# --- Example 1: Basic addition with rounding ---
print("\n--- Addition with Rounding ---")
sum_result = round(x + y)
print(f"Sum (rounded): {sum_result}")

# --- Example 2: Formatting large numbers with commas ---
print("\n--- Formatting with Thousands Separators ---")
sum_result = round(x + y)
print(f"Sum with commas: {sum_result:,}")
print("(Note: Useful for displaying numbers like 1,000 instead of 1000)")

# --- Example 3: Basic division ---
print("\n--- Division (unformatted) ---")
division_result = x / y
print(f"x / y = {division_result}")

# --- Example 4: Division with manual rounding ---
print("\n--- Division with Manual Rounding ---")
division_result = round(x / y, 2)
print(f"x / y (rounded to 2 decimals): {division_result}")

# --- Example 5: Division with f-string formatting ---
print("\n--- Division with F-String Formatting ---")
division_result = x / y
print(f"x / y (formatted to 2 decimals): {division_result:.2f}")
print("(Note: .2f and round() produce the same display result)")