const fs = require("node:fs");
const zlib = require("node:zlib");

const inputString = "blahblahblahblahblah";
console.log(inputString);
const inputBytes = Buffer.from(inputString);
console.log(`Uncompressed length: ${inputBytes.length}`);

// Compress the bytes directly to a .gz file
fs.writeFileSync("compressed.gz", zlib.gzipSync(inputBytes));

// Compress the bytes
const outputBytes = zlib.deflateSync(inputBytes);
console.log(`Compressed length: ${outputBytes.length}`);
// console.log(outputBytes.toString("hex"));

// Decompress the bytes
const result = zlib.inflateSync(outputBytes);

// Decode the bytes to a string
console.log(result.toString());
