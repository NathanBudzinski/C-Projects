# Caesar Cipher encryption, decryption, and brute force decryption

def encrypt(plaintext, shift):
    plaintext = plaintext.upper()
    ciphertext = ''
    for x in plaintext:
        ascii_num = ord(x)
        if ascii_num == ord(' '): continue
        shifted = ascii_num + shift
        if shifted > ord('Z'): shifted -= 26
        ciphertext += chr(shifted)
    return ciphertext

def decrypt(ciphertext, shift): 
    ciphertext = ciphertext.upper()
    plaintext = ''
    for x in ciphertext: 
        ascii_num = ord(x)
        shifted = ascii_num - shift
        if shifted < ord('A'): shifted += 26
        plaintext += chr(shifted)
    return plaintext

def brute_force(ciphertext):
    ciphertext = ciphertext.upper()
    for i in range(1, 26):
        plaintext = ''
        for x in ciphertext:
            ascii_num = ord(x)
            shifted = ascii_num + i
            if shifted > ord('Z'): shifted -= 26
            plaintext += chr(shifted)
        print(plaintext)

def main():
    plaintext = "This is a sample text"
    ciphertext = encrypt(plaintext, 4)
    print("Ciphertext:", ciphertext, '\n')
    print("Plaintext:", decrypt(ciphertext, 4), '\n')
    print("Brute-force decryption: \n")
    brute_force(ciphertext)

main()
