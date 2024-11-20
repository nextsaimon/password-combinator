import itertools
import string

try:
    min_length = int(input("Enter minimum password length: "))
    max_length = int(input("Enter maximum password length: "))
    
    # Validate that min_length is not greater than max_length
    if min_length > max_length:
        raise ValueError("Minimum password length cannot be greater than maximum password length.")
    
    chars = input("Enter characters to use for password (leave blank for all): ")
    if not chars:
        # Use all letters, digits and special characters if no specific chars provided
        chars = string.ascii_letters + string.digits + string.punctuation

    filename = input("Enter filename to save passwords (e.g. pass.txt): ").strip()
    if not filename:
        print("No filename provided. Using default name: pass.txt")
        filename = "pass.txt"

    # Generate all password combinations
    with open(filename, 'w') as f:
        for length in range(min_length, max_length + 1):
            for password in itertools.product(chars, repeat=length):
                # Generate password
                password = ''.join(password)
                # Write to file
                f.write(password + '\n')

    print(f"All password combinations have been generated and saved to {filename}")

except ValueError as ve:
    print(f"Input Error: {ve}")
except FileNotFoundError:
    print("File could not be created. Check the file path and try again.")
except Exception as e:
    print(f"An unexpected error occurred: {e}")
