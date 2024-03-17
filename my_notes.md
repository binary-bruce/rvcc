
## Commit: f86a47f3c31cff17facaf98432520552d06f2d78
## Lesson 1
* Precondition: set up the environment(https://github.com/sunshaoce/rvcc-course/blob/main/install-riscv-1.sh)
* Run test: `RISCV=~/riscv make test`, don't forget to add `RISCV` variable which is required by the shell file
* `ret` is actually pseudo-instruction for `jalr x0, x1, 0`
  * jalr: jump and link register
  * jal: jump and link
  * jalr vs jal: (read more in https://inst.eecs.berkeley.edu/~cs61c/su22/pdfs/discussions/disc04-sols.pdf)
    * `j label` is a pseudo-instruction for `jal x0, label`. (Since it’s writing the return address to x0, it’s effectively discarding it)
    * jalr is used to return to the memory address specified in the second argumen
    * Keep in mind that jal jumps to a label (which is translated into an immediate by the assembler), whereas jalr jumps to an address stored in a register, which is set at runtime
  * The x1 ra register is used to save the subroutine / function return addresses. Before a subroutine call is performed, x1 is explicitly set to the subroutine return address which is usually pc + 4
  * The standard software calling convention uses x1 register to hold the return address on a function call.
