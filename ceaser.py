alph = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']

def encrypt(text, key):
    encrypted_text = ''
    for char in text:
        if char in alph:
            new_index = (alph.index(char) + key) % len(alph)
            encrypted_text += alph[new_index]
        else:
            encrypted_text += char  # if the character is not in alph, leave it unchanged
    return encrypted_text

text = input("Enter the word to encrypt: ").lower()  # Convert input to lowercase to match alph
key = int(input("Enter the key value: "))
encrypted = encrypt(text, key)
print("Encrypted word:", encrypted)
