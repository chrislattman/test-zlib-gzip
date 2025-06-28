use std::{
    fs::File,
    io::{Read, Write},
    str,
};

use flate2::{Compression, GzBuilder, read::ZlibDecoder, write::ZlibEncoder};

fn main() {
    let input_string = "blahblahblahblahblah";
    println!("{input_string}");
    let input_bytes = input_string.as_bytes();
    println!("Uncompressed length: {}", input_bytes.len());

    // Compress the bytes directly into a .gz file
    let f = File::create("compressed.gz").unwrap();
    let mut gz = GzBuilder::new().write(f, Compression::best());
    gz.write_all(input_bytes).unwrap();
    gz.finish().unwrap();

    // Compress the bytes
    let mut compressor = ZlibEncoder::new(Vec::new(), Compression::best());
    compressor.write_all(input_bytes).unwrap();
    let output_bytes = compressor.finish().unwrap();
    println!("Compressed length: {}", output_bytes.len());
    // for byte in output_bytes.iter() {
    //     print!("{byte:02x?}");
    // }
    // println!();

    // Decompress the bytes
    let mut decompressor = ZlibDecoder::new(&output_bytes[..]);
    let mut result = [0u8; 100];
    decompressor.read_exact(&mut result).unwrap(); // also decompressor.read_to_string()

    // Decode the bytes to a str
    println!("{}", str::from_utf8(&result).unwrap());
}
