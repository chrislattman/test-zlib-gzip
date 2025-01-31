java:
	javac Compression.java
	java Compression

python:
	python3 compression.py

nodejs:
	node compression.js

go:
	go build go/compression.go
	./compression

rust:
	cargo build -q --bin compression
	./target/debug/compression

c:
	gcc -Wall -Wextra -Werror -pedantic -std=c99 -o compression compression.c -lz
	./compression

csharp:
	dotnet build
	./bin/Debug/net9.0/test-zlib-gzip

clean:
	rm -rf *.class target compression *.exe *.gz bin obj

.PHONY: java python nodejs go rust c clean
