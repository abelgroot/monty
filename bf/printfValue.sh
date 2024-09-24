read -p "Enter a character: " input_char
ascii_value=$(printf "%d" "'$input_char")
echo "ASCII value of $input_char: $ascii_value"
