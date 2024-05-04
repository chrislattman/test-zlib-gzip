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
	cargo build --bin compression
	./target/debug/compression

c:
	gcc -Wall -Wextra -Werror -pedantic -std=c99 -o compression compression.c -lz
	./compression

clean:
	rm -rf *.class target compression *.gz

.PHONY: java python nodejs go rust c clean
