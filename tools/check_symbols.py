import re


def main():
    symbols = set()
    addresses = set()

    with open("config/symbols.txt", "r", encoding="utf8") as f:
        for line in f:
            line = line.strip()

            if line and not line.startswith("//"):
                found = re.search(r"(.+?)\s+\=\s+0x([0-9-a-zA-Z]+);?", line)

                if found:
                    name = found.group(1).strip()
                    addr = int(found.group(2), 16)
                    
                    if addr in addresses:
                        print(f"Duplicate address found: {addr:08x} for symbol {name}")
                    elif name in symbols:
                        print(f"Duplicate symbol found: {name} at address {addr:08x}")
                    else:
                        symbols.add(name)
                        addresses.add(addr)


if __name__ == "__main__":
    main()
