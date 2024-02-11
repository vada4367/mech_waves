CC=cc
LD=ld
FORMAT=clang-format
CFLAGS=-std=gnu99 -Wall -Wextra -pedantic
BUILD_DIR=./obj_files
SRC_DIR=./src
HEADERS_DIR=${SRC_DIR}/headers
BIN=./bin/main

build:
	${CC} -o ${BUILD_DIR}/atom.o ${CFLAGS}    				-c ${SRC_DIR}/atom.c 
	${CC} -o ${BUILD_DIR}/material_env.o ${CFLAGS}    -c ${SRC_DIR}/material_env.c 
	${CC} -o ${BIN} ${CFLAGS} ${SRC_DIR}/main.c ${BUILD_DIR}/atom.o ${BUILD_DIR}/material_env.o

fmt:
	${FORMAT} --style=GNU ${SRC_DIR}/main.c > ${SRC_DIR}/main1.c
	${FORMAT} --style=GNU ${SRC_DIR}/material_env.c > ${SRC_DIR}/material_env1.c
	${FORMAT} --style=GNU ${SRC_DIR}/atom.c > ${SRC_DIR}/atom1.c

	${FORMAT} --style=GNU ${HEADERS_DIR}/env.h > ${HEADERS_DIR}/env1.h
	${FORMAT} --style=GNU ${HEADERS_DIR}/atom.h > ${HEADERS_DIR}/atom1.h

	rm -rf ${SRC_DIR}/main.c ${SRC_DIR}/material_env.c ${SRC_DIR}/atom.c
	rm -rf ${HEADERS_DIR}/env.h ${HEADERS_DIR}/atom.h

	mv ${SRC_DIR}/main1.c ${SRC_DIR}/main.c
	mv ${SRC_DIR}/atom1.c ${SRC_DIR}/atom.c
	mv ${SRC_DIR}/material_env1.c ${SRC_DIR}/material_env.c

	mv ${HEADERS_DIR}/env1.h ${HEADERS_DIR}/env.h
	mv ${HEADERS_DIR}/atom1.h ${HEADERS_DIR}/atom.h

clean:
	rm -rf ${BUILD_DIR}/*
	rm -rf ${BIN}

run: build
	${BIN}
