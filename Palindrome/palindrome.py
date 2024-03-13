# Nathan Budzinski
# Checks if a user inputted string is palindromic

def reverse_string(str):
    return str[::-1]


def is_palindrome(str):
    return str.lower() == reverse_string(str).lower()


def main():
    str = input('Enter a string: ')
    if str != '':
        if is_palindrome(str):
            if len(str) % 2 == 0:
                print(f'{str} is an even palindrome\n')
            else:
                print(f'{str} is an odd palindrome\n')
        else:
            print(f'Reverse string: {reverse_string(str)}')
            print(f'{str} is not a palindrome\n')


main()
