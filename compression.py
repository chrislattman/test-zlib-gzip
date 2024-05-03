import gzip
import zlib

inputString = "blahblahblahblahblah"
print(inputString)
inputBytes = inputString.encode()
print(f"Uncompressed length: {len(inputBytes)}")

# Compress the bytes directly to a .gz file
# with gzip.open("compressed.gz", "wb") as f:
#     f.write(inputBytes)
open("compressed.gz", "wb").write(gzip.compress(inputBytes)) # For some reason this is better

# Compress the bytes
outputBytes = zlib.compress(inputBytes)
print(f"Compressed length: {len(outputBytes)}")
# print(outputBytes.hex())

# Decompress the bytes
result = zlib.decompress(outputBytes)

# Decode the bytes to a str
print(result.decode())
