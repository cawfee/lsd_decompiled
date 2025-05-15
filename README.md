# LSD Decompiled

A work-in-progress decompilation of LSD: Dream Emulator for the PlayStation 1.

## About

LSD: Dream Emulator is a surreal exploration game developed by Asmik Ace Entertainment and released exclusively in Japan for the PlayStation in 1998. This project aims to create a fully functional decompilation that can be compiled back into a playable game matching the original.

## Project Status

This project is in the early stages of development. Many functions are still being identified and filenames are still a work in progress and are not yet final. Contributions are welcome!

## Setup Instructions

### Requirements

To build this project you will need:

- A Linux environment or WSL2 for Windows.
- Python3.8 or newer
- Git

### 1. Clone the Repository

```bash
git clone https://github.com/cawfee/lsd_decompiled.git
cd lsd_decompiled
```

### 2. Install Dependencies

Debian based systems:

```bash
sudo apt update
sudo apt install python3 python3-pip git build-essential gcc-mipsel-linux-gnu binutils-mipsel-linux-gnu
pip3 install -r requirements.txt
```

### 3. Setting up the ROM

You must provide your own copy of the game. From the game disk, copy the executable "SLPS_015.56" to rom/SLPS_015.56

Expected hash of the executable:
- SHA1: `76322eeade5ebb22dca57fdeac7d68c30f06308d`
- SHA256: `282308ade239ce61b5603651dbbab0476a681b5d3618e82c0d3c3a95316d302f`

### 4. Building

```bash
python3 configure.py setup  # First time only
python3 configure.py
ninja split
ninja check
```

If successful, the hash of the built executable will pass the check.

## Special Thanks

- [FirecatFG's decompilation](https://github.com/FirecatFG/lsddecomp/) - For identifying the original toolchain and providing initial segments that helped overcome early obstacles in this project.
- All the contributors to the PS1 decompilation community
- The creators of splat, maspsx, and other tools that make this possible

## Disclaimer

This project is not affiliated with or endorsed by Asmik Ace Entertainment, OutSide Directors Company (ODC), Osamu Sato, Sony, or any entities associated with LSD: Dream Emulator.
