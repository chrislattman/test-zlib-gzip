#include <stdio.h>
#include <string.h>
#include <zlib.h>

int main(void)
{
    gzFile file;
    z_stream defstrm, infstrm;
    unsigned char outputBytes[100];
    char result[100];

    const char *inputString = "blahblahblahblahblah";
    printf("%s\n", inputString);
    printf("Uncompressed length: %zu\n", strlen(inputString));

    // Compress the bytes directly to a .gz file
    file = gzopen("compressed.gz", "wb");
    gzwrite(file, inputString, strlen(inputString)); // same as gzputs(file, inputString);
    gzclose(file);

    // Compress the bytes
    defstrm.zalloc = Z_NULL;
    defstrm.zfree = Z_NULL;
    defstrm.opaque = Z_NULL;
    defstrm.avail_in = strlen(inputString);
    defstrm.next_in = (Bytef *) inputString;
    defstrm.avail_out = sizeof(outputBytes);
    defstrm.next_out = outputBytes;
    deflateInit(&defstrm, Z_BEST_COMPRESSION);
    deflate(&defstrm, Z_FINISH);
    deflateEnd(&defstrm);
    // printf("Compressed length: %lu\n", defstrm.total_out);
    // for (unsigned long i = 0; i < defstrm.total_out; i++) {
    //     printf("%02x", outputBytes[i]);
    // }
    // printf("\n");

    // Decompress the bytes
    infstrm.zalloc = Z_NULL;
    infstrm.zfree = Z_NULL;
    infstrm.opaque = Z_NULL;
    infstrm.avail_in = defstrm.total_out;
    infstrm.next_in = outputBytes;
    infstrm.avail_out = sizeof(result);
    infstrm.next_out = (Bytef *) result;
    inflateInit(&infstrm);
    inflate(&infstrm, Z_NO_FLUSH);
    inflateEnd(&infstrm);

    // Decode the bytes to a string
    result[infstrm.total_out] = '\0';
    printf("%s\n", result);
}
