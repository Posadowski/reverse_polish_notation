# Reverse Polish Notation Calculator

This is a simple program written in C that converts algebraic expressions into Reverse Polish Notation (RPN) and then evaluates their value.

## Getting Started

To use this program, follow these steps:

1. Clone the repository to your local machine:

   ```sh
   git clone https://github.com/Posadowski/reverse_polish_notation.git
   ```

2. Compile the C code using the provided Makefile:

   ```sh
   cd reverse_polish_notation
   make
   ```

3. This will create an executable file named `reverse_polish_notation.exe`.

## Usage

Once the program is compiled, you can run it from the command line. The program will prompt you to enter an algebraic expression, which it will then convert to RPN and calculate its value.

Here's an example of how to run the program:

```sh
./reverse_polish_notation.exe
Enter an algebraic expression: 2*(2+1)
Result: 6.00
```

## Supported Operators

The program supports the following operators:
- Addition `+`
- Subtraction `-`
- Multiplication `*`
- Division `/`
- Parentheses `(` and `)`

## Contributions

If you'd like to contribute to this project, feel free to open an issue or submit a pull request. Your contributions are welcome!

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Acknowledgments

This project was created as a learning exercise in C programming and the implementation of the Reverse Polish Notation algorithm.

Enjoy using the Reverse Polish Notation Calculator!
