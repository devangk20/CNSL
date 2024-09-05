def generate_key_matrix(keyword):
    # Remove duplicates and create a unique sequence of characters for the key matrix
    keyword = "".join(sorted(set(keyword), key=keyword.index))
    alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"  # J is typically combined with I in Playfair
    matrix = []
    
    for char in keyword.upper():
        if char not in matrix and char in alphabet:
            matrix.append(char)
    
    for char in alphabet:
        if char not in matrix:
            matrix.append(char)
    
    # Arrange the key into a 5x5 matrix
    matrix = [matrix[i:i + 5] for i in range(0, 25, 5)]
    return matrix

def format_text(text):
    text = text.upper().replace("J", "I")
    formatted = ""
    
    i = 0
    while i < len(text):
        formatted += text[i]
        if i + 1 < len(text) and text[i] == text[i + 1]:
            formatted += "X"
        elif i + 1 < len(text):
            formatted += text[i + 1]
            i += 1
        i += 1
    
    if len(formatted) % 2 != 0:
        formatted += "X"  # Add an extra X if the length of the text is odd
    
    return formatted

def find_position(matrix, char):
    for row in range(5):
        for col in range(5):
            if matrix[row][col] == char:
                return row, col
    return None

def encrypt_pair(pair, matrix):
    row1, col1 = find_position(matrix, pair[0])
    row2, col2 = find_position(matrix, pair[1])

    if row1 == row2:
        return matrix[row1][(col1 + 1) % 5] + matrix[row2][(col2 + 1) % 5]
    elif col1 == col2:
        return matrix[(row1 + 1) % 5][col1] + matrix[(row2 + 1) % 5][col2]
    else:
        return matrix[row1][col2] + matrix[row2][col1]

def decrypt_pair(pair, matrix):
    row1, col1 = find_position(matrix, pair[0])
    row2, col2 = find_position(matrix, pair[1])

    if row1 == row2:
        return matrix[row1][(col1 - 1) % 5] + matrix[row2][(col2 - 1) % 5]
    elif col1 == col2:
        return matrix[(row1 - 1) % 5][col1] + matrix[(row2 - 1) % 5][col2]
    else:
        return matrix[row1][col2] + matrix[row2][col1]

def playfair_encrypt(plain_text, keyword):
    matrix = generate_key_matrix(keyword)
    formatted_text = format_text(plain_text)
    encrypted_text = ""
    
    for i in range(0, len(formatted_text), 2):
        encrypted_text += encrypt_pair(formatted_text[i:i+2], matrix)
    
    return encrypted_text

def playfair_decrypt(cipher_text, keyword):
    matrix = generate_key_matrix(keyword)
    decrypted_text = ""
    
    for i in range(0, len(cipher_text), 2):
        decrypted_text += decrypt_pair(cipher_text[i:i+2], matrix)
    
    return decrypted_text

# Example usage
keyword = "PLAYFAIR"
plain_text = "HIDETHEGOLDINTHETREXESTUMP"

encrypted_text = playfair_encrypt(plain_text, keyword)
decrypted_text = playfair_decrypt(encrypted_text, keyword)

print(f"Plain Text: {plain_text}")
print(f"Encrypted Text: {encrypted_text}")
print(f"Decrypted Text: {decrypted_text}")
