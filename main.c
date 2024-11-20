#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate all combinations of passwords
void generatePasswords(int min_length, int max_length, const char *chars, const char *filename)
{
  FILE *file = fopen(filename, "w");
  if (!file)
  {
    printf("File could not be created. Check the file path and try again.\n");
    return;
  }

  int chars_len = strlen(chars);

  // Generate combinations for each length
  for (int length = min_length; length <= max_length; length++)
  {
    int *indices = calloc(length, sizeof(int));
    if (!indices)
    {
      printf("Memory allocation failed.\n");
      fclose(file);
      return;
    }

    while (1)
    {
      // Generate a password based on the indices
      char *password = calloc(length + 1, sizeof(char));
      if (!password)
      {
        printf("Memory allocation failed.\n");
        free(indices);
        fclose(file);
        return;
      }

      for (int i = 0; i < length; i++)
      {
        password[i] = chars[indices[i]];
      }

      fprintf(file, "%s\n", password);
      free(password);

      // Increment indices
      int i;
      for (i = length - 1; i >= 0; i--)
      {
        if (indices[i] < chars_len - 1)
        {
          indices[i]++;
          break;
        }
        indices[i] = 0;
      }

      if (i < 0)
        break; // If all combinations are exhausted
    }

    free(indices);
  }

  fclose(file);
  printf("All password combinations have been generated and saved to %s\n", filename);
}

int main()
{
  int min_length, max_length;
  char chars[256];
  char filename[256];

  printf("Enter minimum password length: ");
  if (scanf("%d", &min_length) != 1)
  {
    printf("Invalid input for minimum password length.\n");
    return 1;
  }

  printf("Enter maximum password length: ");
  if (scanf("%d", &max_length) != 1)
  {
    printf("Invalid input for maximum password length.\n");
    return 1;
  }

  if (min_length > max_length)
  {
    printf("Error: Minimum password length cannot be greater than maximum password length.\n");
    return 1;
  }

  printf("Enter characters to use for password (leave blank for all): ");
  getchar(); // Consume the newline left by scanf
  fgets(chars, sizeof(chars), stdin);

  // Remove newline character from fgets
  size_t len = strlen(chars);
  if (len > 0 && chars[len - 1] == '\n')
  {
    chars[len - 1] = '\0';
  }

  if (strlen(chars) == 0)
  {
    strcpy(chars, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;':,.<>?/~`"); // Default chars
  }

  printf("Enter filename to save passwords (e.g. pass.txt): ");
  fgets(filename, sizeof(filename), stdin);

  // Remove newline character from fgets
  len = strlen(filename);
  if (len > 0 && filename[len - 1] == '\n')
  {
    filename[len - 1] = '\0';
  }

  if (strlen(filename) == 0)
  {
    strcpy(filename, "pass.txt");
    printf("No filename provided. Using default name: pass.txt\n");
  }

  generatePasswords(min_length, max_length, chars, filename);

  return 0;
}
