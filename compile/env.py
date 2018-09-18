from os.path import dirname, realpath, join

PROJ_ROOT = dirname(dirname(realpath(__file__)))

TOOLCHAIN_ROOT = join(PROJ_ROOT, "wasm-waterfall", "src", "work", "wasm-install")

WASM_LIB_DIR = join(PROJ_ROOT, "wasm", "lib")

SYSROOT = join(TOOLCHAIN_ROOT, "sysroot")

TARGET_TRIPLE = "wasm32-unknown-unknown-wasm"
CONFIG_TARGET = "wasm32"

COMPILER_FLAGS = [
    "--target={}".format(TARGET_TRIPLE),
    "--sysroot={}".format(SYSROOT),
]

COMPILER_FLAGS_STRING = " ".join(COMPILER_FLAGS)
COMPILER_FLAGS_STRING = "\"{}\"".format(COMPILER_FLAGS_STRING)

CC = join(TOOLCHAIN_ROOT, "bin", "clang")
CFLAGS = COMPILER_FLAGS_STRING
CXX = join(TOOLCHAIN_ROOT, "bin", "clang++")
CXXFLAGS = COMPILER_FLAGS_STRING
CROSS_COMPILE = join(TOOLCHAIN_ROOT, "llvm-")

CPP = join(TOOLCHAIN_ROOT, "bin", "clang-cpp")

_ENV_TUPLES = [
    ("CC", CC),
    ("CFLAGS", CFLAGS),
    ("CPP", CPP),
    ("CXX", CXX),
    ("CXXFLAGS", CXXFLAGS),
    ("CROSS_COMPILE", CROSS_COMPILE),
]

ENV_DICT = {e[0]: e[1] for e in _ENV_TUPLES}
ENV_STR = " ".join(["{}={}".format(e[0], e[1]) for e in _ENV_TUPLES])