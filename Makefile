java:
	javac Compression.java
	java Compression

python:
	python3 test_compression.py

nodejs:
	node compression.js

go:
	go build go/compression.go
	./compression

rust:
	cargo build -q --bin compression
	./target/debug/compression

c:
	cmake --build build -- --quiet
	cmake --build build --target run-compression -- --quiet
# 	gcc -Wall -Wextra -Werror -pedantic -std=c99 -o compression compression.c -lz
# 	./compression

csharp:
	dotnet build -v q
	./bin/Debug/net10.0/test-zlib-gzip

clean:
	rm -rf *.class target compression *.exe *.gz bin obj

.PHONY: java python nodejs go rust c csharp clean
