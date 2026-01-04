# set -xe

CC=gcc-14
# CC=gcc-15
# CC=clang-19
# CC=clang-20

# CFLAGS=(-I.. -Wall -Wextra -Wno-comment -ggdb3 -std=gnu11 -fsanitize=address)
CFLAGS=(
  -I.. -Wall -Wextra
  -Wno-comment
  -Wno-char-subscripts
  -ggdb3
  -fsanitize=address
  -fsanitize=signed-integer-overflow
)
CFLAGS+=(-std=gnu11)
# CFLAGS+=(-pg)
# CFLAGS+=(-std=gnu23)
# CFLAGS+=(-std=c23)
# CFLAGS+=(-O2)
CFLAGS+=(-O0)

$CC ${CFLAGS[@]} solution.c run.c && time ./a.out
