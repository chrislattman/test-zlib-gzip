import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.zip.DataFormatException;
import java.util.zip.Deflater;
import java.util.zip.GZIPOutputStream;
import java.util.zip.Inflater;

public class Compression {
    public static void main(String[] args) throws DataFormatException, FileNotFoundException, IOException {
        String inputString = "blahblahblahblahblah";
        System.out.println(inputString);
        byte[] inputBytes = inputString.getBytes(StandardCharsets.UTF_8);
        System.out.println("Uncompressed length: " + inputBytes.length);

        // Compress the bytes directly to a .gz file
        GZIPOutputStream gzos = new GZIPOutputStream(new FileOutputStream("compressed.gz"));
        gzos.write(inputBytes);
        gzos.close();

        // Compress the bytes
        byte[] outputBytes = new byte[100];
        Deflater compressor = new Deflater();
        compressor.setInput(inputBytes);
        compressor.finish();
        int compressedLength = compressor.deflate(outputBytes);
        compressor.end();
        System.out.println("Compressed length: " + compressedLength);
        // for (int i = 0; i < compressedLength; i++) {
        //     String st = String.format("%02x", outputBytes[i]);
        //     System.out.print(st);
        // }
        // System.out.println();

        // Decompress the bytes
        Inflater decompressor = new Inflater();
        decompressor.setInput(outputBytes, 0, compressedLength);
        byte[] result = new byte[100];
        int uncompressedLength = decompressor.inflate(result);
        decompressor.end();

        // Decode the bytes into a String
        System.out.println(new String(result, 0, uncompressedLength, StandardCharsets.UTF_8));
    }
}
