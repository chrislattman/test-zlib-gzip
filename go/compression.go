package main

import (
	"bytes"
	"compress/gzip"
	"compress/zlib"
	// "encoding/hex"
	"fmt"
	"os"
)

// For some reason Go doesn't compress as well as the other languages
func main() {
	inputString := "blahblahblahblahblah"
	fmt.Println(inputString)
	inputBytes := []byte(inputString)
	fmt.Println("Uncompressed length:", len(inputBytes))

	// Compress the bytes directly into a .gz file
	var buf bytes.Buffer
	gzw := gzip.NewWriter(&buf)
	gzw.Write(inputBytes)
	gzw.Close()
	os.WriteFile("compressed.gz", buf.Bytes(), 0644)

	// Compress the bytes
	var b bytes.Buffer
	w := zlib.NewWriter(&b)
	w.Write(inputBytes)
	w.Close()
	fmt.Println("Compressed length:", b.Len())
	// fmt.Println(hex.EncodeToString(b.Bytes()))

	// Decompress the bytes
	r, _ := zlib.NewReader(&b)
	result := make([]byte, 100)
	r.Read(result)
	r.Close()

	// Decode the bytes into a string
	outputString := string(result)
	fmt.Println(outputString)
}
