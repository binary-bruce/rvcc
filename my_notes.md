## [3] 加入一个终结符解析器，来解析终结符间的空格 [Commit](https://github.com/binary-bruce/rvcc/commit/4887f1b19741f8726fede76fecc4423bfcee37b9)
* For small/toy/short-lived programs, to simplify, it's ok not to free a memory.
* [va_list](https://hackernoon.com/what-is-va_list-in-c-exploring-the-secrets-of-ft_printf) for variable arguments
* [strtoul](https://www.runoob.com/cprogramming/c-function-strtoul.html)
* Conceptual model change: instead of parsing the input as a string, transform the input as a list of tokens, then process the token one by one
  * token 1 -> token 2 -> token 3 -> EOF

Practise: implement tokenizing ' 12 + 34 - 5 ' in a more OOP way(maybe in Rust)

## [2] 支持+ -运算符 [Commit](https://github.com/binary-bruce/rvcc/commit/6720c912790b43e5c6adb0b73db95cef478b574d) 
* [strtol](https://en.cppreference.com/w/c/string/byte/strtol)
* use addi for substraction: `addi rd, rs, (-imm)`

Practise: use `strtol` to extract numbers from "1+23-44"

## [1] 编译出能返回指定数值的程序 [Commit](https://github.com/binary-bruce/rvcc/commit/f86a47f3c31cff17facaf98432520552d06f2d78)
* Precondition: [set up the environment](https://github.com/sunshaoce/rvcc-course/blob/main/install-riscv-1.sh)
* Run test: `RISCV=~/riscv make test`, don't forget to add `RISCV` variable which is required by the shell file
* `ret` is actually pseudo-instruction for `jalr x0, x1, 0`
  * jalr: jump and link register
  * jal: jump and link
  * jalr vs jal: (read more in [here](https://inst.eecs.berkeley.edu/~cs61c/su22/pdfs/discussions/disc04-sols.pdf)
    * `j label` is a pseudo-instruction for `jal x0, label`. (Since it’s writing the return address to x0, it’s effectively discarding it)
    * jalr is used to return to the memory address specified in the second argumen
    * Keep in mind that jal jumps to a label (which is translated into an immediate by the assembler), whereas jalr jumps to an address stored in a register, which is set at runtime
  * The x1 ra register is used to save the subroutine / function return addresses. Before a subroutine call is performed, x1 is explicitly set to the subroutine return address which is usually pc + 4
  * The standard software calling convention uses x1 register to hold the return address on a function call.


[Markdown syntax](https://www.markdownguide.org/basic-syntax/)
