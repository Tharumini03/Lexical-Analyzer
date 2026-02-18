# RPAL Lexical Scanner (C++)

A simple lexical scanner for the RPAL language implemented in C++.

This program reads a `.txt` source file and outputs tokens in the format:

<TOKEN_TYPE, "VALUE">

---

## 📌 Features

The scanner identifies:

- ✅ Keywords
- ✅ Identifiers
- ✅ Integers
- ✅ Strings
- ✅ Operators
- ✅ Punctuation symbols
- ✅ Comments (`//`)
- ✅ Whitespace handling
- ✅ Basic lexical error detection

---

## 📂 Supported Token Types

| Token Type    | Example Output |
|---------------|----------------|
| KEYWORD       | `<KEYWORD, "let">` |
| IDENTIFIER    | `<IDENTIFIER, "x">` |
| INTEGER       | `<INTEGER, "123">` |
| STRING        | `<STRING, "hello">` |
| OPERATOR      | `<OPERATOR, "=">` |
| PUNCTUATION   | `<PUNCTUATION, "(">` |
| ERROR         | `<ERROR, "Invalid symbol: @">` |

---

## 🚀 How To Compile

### Linux / Mac / VS Code Terminal

```bash
g++ scanner.cpp -o scanner
