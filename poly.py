def generate_vigenere_table():
    table = []
    for i in range(26):
        row = [(chr((i + j) % 26 + 65)) for j in range(26)]
        table.append(row)
    return table

def repeat_keyword(keyword, length):
    return (keyword * (length // len(keyword) + 1))[:length]

def encrypt(plain_text, keyword):
    table = generate_vigenere_table()
    keyword_repeated = repeat_keyword(keyword.upper(), len(plain_text))
    cipher_text = ""

    for p_char, k_char in zip(plain_text.upper(), keyword_repeated):
        if p_char.isalpha():  # Encrypt only alphabetic characters
            row = ord(k_char) - 65
            col = ord(p_char) - 65
            cipher_text += table[row][col]
        else:
            cipher_text += p_char  # Non-alphabetic characters are not encrypted

    return cipher_text

def decrypt(cipher_text, keyword):
    table = generate_vigenere_table()
    keyword_repeated = repeat_keyword(keyword.upper(), len(cipher_text))
    plain_text = ""

    for c_char, k_char in zip(cipher_text.upper(), keyword_repeated):
        if c_char.isalpha():  # Decrypt only alphabetic characters
            row = ord(k_char) - 65
            col = table[row].index(c_char)
            plain_text += chr(col + 65)
        else:
            plain_text += c_char  # Non-alphabetic characters are not decrypted

    return plain_text

# Example usage
plain_text = "ATTACKATDAWN"
keyword = "LEMON"

encrypted_text = encrypt(plain_text, keyword)
decrypted_text = decrypt(encrypted_text, keyword)

print(f"Plain Text: {plain_text}")
print(f"Keyword: {keyword}")
print(f"Encrypted Text: {encrypted_text}")
print(f"Decrypted Text: {decrypted_text}")
