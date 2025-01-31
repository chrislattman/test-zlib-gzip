using System.IO.Compression;

string inputString = "blahblahblahblahblah";
Console.WriteLine(inputString);
byte[] inputBytes = System.Text.Encoding.UTF8.GetBytes(inputString);
Console.WriteLine("Uncompressed length: " + inputBytes.Length);

// Compress the bytes directly to a .gz file
GZipStream gzstream = new(File.Create("compressed.gz"), CompressionMode.Compress);
gzstream.Write(inputBytes);
gzstream.Close();

// Compress the bytes
MemoryStream ostream = new();
ZLibStream compressor = new(ostream, CompressionMode.Compress, false);
compressor.Write(inputBytes);
compressor.Dispose();
byte[] outputBytes = ostream.ToArray();
Console.WriteLine("Compressed length: " + outputBytes.Length);
// foreach (byte b in outputBytes)
// {
//     Console.Write(b.ToString("x2"));
// }
// Console.WriteLine();

// Decompress the bytes
MemoryStream istream = new(outputBytes, false);
ZLibStream decompressor = new(istream, CompressionMode.Decompress, false);
byte[] result = new byte[100];
int uncompressedLength = decompressor.Read(result);
compressor.Dispose();

// Decode the bytes into a string
Console.WriteLine(System.Text.Encoding.UTF8.GetString(result, 0, uncompressedLength));
