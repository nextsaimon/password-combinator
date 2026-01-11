# Password Combinator

A script to generate all possible password combinations based on user-defined criteria and save them to a file. Available in both Python and C versions.

## Features
- Generate passwords of custom lengths (minimum and maximum).
- Use specific characters or the entire set of letters, digits, and special symbols.
- Automatically saves generated passwords to a file (default: `pass.txt` if no filename is provided).

## Requirements

### For Python
- Python 3.x
- No additional libraries are needed; the script uses the standard Python library.

### For C
- A C compiler (e.g., GCC or Clang).

## How to Use

### Python Version
1. Clone the repository:
   ```bash
   git clone https://github.com/nextSaimon/password-combinator.git
   cd password-combinator
   python -u main.py
