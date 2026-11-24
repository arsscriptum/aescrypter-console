<center>
<img src="img/title.png" alt="title" />
</center>

AES Crypt is file encryption software available on several operating systems that uses the industry standard Advanced Encryption Standard (AES) to easily and securely encrypt files.

You do not need to be an expert to use AES Crypt, nor do you need to understand cryptography. AES Crypt is designed to be as simple to use as possible, yet still provide the strongest encryption strength available. With over a million downloads, AES Crypt has made it easy for so many people to secure information.

Using a powerful 256-bit encryption algorithm, AES Crypt can safely secure your most sensitive files. Once a file is encrypted, you do not have to worry about a person reading your sensitive information, as an encrypted file is completely useless without the password. It simply cannot be read.

AES Crypt is the perfect tool for anyone who carries sensitive information with them while traveling, uploads sensitive files to servers on the Internet, or wishes to protect sensitive information from being stolen from the home or office. AES Crypt is also the perfect solution for those who wish to backup information and store that data at a bank, in a cloud-based storage service, and any place where sensitive files might be accessible by someone else.

## Usage

```bash

AesCrypter.exe v1.17 - Encryption/Decryption tool using AES.
Copyright(C) 1999 - 2023  Guillaume Plante
arsscriptum - arsscriptum.github.io

[error] Error: You must specify exactly one operation (--encrypt, --decrypt, or --analyse)
Usage: aescrypter.exe {--encrypt|--decrypt|--analyse} file [options]

Operations:
  -d, --decrypt              : decrypt a file
  -e, --encrypt              : encrypt a file
  -a, --analyse              : analyse a file

Options:
  -p, --password <string>    : use clear password string
  -c, --cert <path>          : use certificate
  -o, --output <path>        : output file
  -k, --key-file <path>      : encrypt/decrypt using a key stored in a file
  -f, --force                : overwrite output file if exists
  -g, --generate <path>      : only with 'encrypt' option: generate a key and store in a file
  -h, --help                 : show this help message
```

## Examples

```bash
 > AesCrypter.exe -e "file.zip"
```

## Build

1. Get the ```BuildAutomation``` suite
1. run ```./Build.bat```


## Contributors

1. Glenn Washburn <crass@berlios.de>
1. Paul E. Jones <paulej@packetizer.com>
1. Mauro Gilardi <galvao.m@gmail.com>
1. Guilaume Plante 2020 <gp@arsscriptum>

## Linux Port

1. Guilaume Plante 2025 <gp@arsscriptum>
